import 'dart:async';
import 'dart:ffi';
import 'dart:isolate';
import 'dart:typed_data';

import 'package:flutter/foundation.dart';
import 'package:flutter_mavlink/flutter_mavlink.dart';
import 'package:flutter_mavlink/mavlink_msg.dart';
import 'package:ffi/ffi.dart';
import 'socket.dart';

enum Worker_Isolate_Command {
  Unknown,
  Resume,
  Suspend
}

class WorkerIsolate{
  static WorkerIsolate _instance;
  factory WorkerIsolate() =>_getInstance();
  static WorkerIsolate get instance => _getInstance();
  WorkerIsolate._internal() {
    // 初始化
    _createWorkerIsolate();
  }
  static WorkerIsolate _getInstance() {
    if (_instance == null) {
      _instance = WorkerIsolate._internal();
    }
    return _instance;
  }

  // 新的 isolate 端口
  // 该端口将在未来,用来给 isolate 发送消息
  SendPort sendPort;
  Isolate isolate;

  //默认主程序监听端口
  ReceivePort defaultReceivePort;
  
  //默认主程序接收消息处理
  void onDefultReceivedWorkerIsolateMsgFunction(dynamic message){

  }

  void _createWorkerIsolate() async {
      
      // 本地临时 ReceivePort,用于检索新的 isolate 的 SendPort
      ReceivePort receivePort = ReceivePort();
      defaultReceivePort = ReceivePort();
      defaultReceivePort.listen(onDefultReceivedWorkerIsolateMsgFunction);
      // 初始化新的 isolate
      isolate = await Isolate.spawn(
          callbackFunction,
          receivePort.sendPort,
      );

      // 检索要用于进一步通信的端口
      sendPort = await receivePort.first;
      resume();
  }

  void resume(){
    CrossIsolatesMessage msg = CrossIsolatesMessage<Worker_Isolate_Command>(
              sender: defaultReceivePort.sendPort,
              message: Worker_Isolate_Command.Resume,
          );
    //sendPort?.send(msg);
  }

  void suspend(){
    CrossIsolatesMessage msg = CrossIsolatesMessage<Worker_Isolate_Command>(
              sender: defaultReceivePort.sendPort,
              message: Worker_Isolate_Command.Suspend,
          );
    //sendPort?.send(msg);
  }

  void killWorkerIsolate(){
    isolate?.kill(priority: Isolate.immediate);
    isolate = null;
  }

  // 新 isolate 的入口
  static void callbackFunction(SendPort callerSendPort){
      // 一个 SendPort 实例，用来接收来自调用者的消息
      ReceivePort newIsolateReceivePort = ReceivePort();
      // 向调用者提供此 isolate 的 SendPort 引用
      callerSendPort.send(newIsolateReceivePort.sendPort);
  
      // 监听输入报文、处理并提供回复的
      // Isolate 主程序
      newIsolateReceivePort.listen((dynamic message){
          CrossIsolatesMessage incomingMessage = message as CrossIsolatesMessage;
          // 处理消息
          if(incomingMessage.message is Worker_Isolate_Command){
            WorkerIsolate().onReceivedCommandMsg(incomingMessage);
          } else if(incomingMessage.message is int) {
            UdpSocketManager().sendData(incomingMessage.extra);
          } else if(incomingMessage.message is Uint8List){
            WorkerIsolate().parserUdpDataHandler(incomingMessage);
          }
      });
  }

  void parserUdpDataHandler(CrossIsolatesMessage incomingMessage) {
    int msgId = getMavLinkMsgFromBuffer(incomingMessage.message);
    print('received msgId :$msgId');
    switch (msgId) {
      case MAVLINK_MSG_ID_HEARTBEAT:
      {
        Pointer<MavlinkHeartbeat> msgPointer = decodeHeartbeatMsg();
        MavlinkHeartbeat msg = msgPointer.ref;
        print('heartbeat type:${msg.type} base_mode:${msg.base_mode} system_status :${msg.system_status}');
        free(msgPointer);
      }
        
        break;
      default:
    }
    incomingMessage.sender.send(MavlinkHeartbeat);
    
  }

  Future<Struct> parserUdpData(Uint8List data) async{
    ReceivePort port = ReceivePort();
      // 发送消息到 Isolate，并且通知该 isolate 哪个端口是用来提供回复的
    sendPort?.send(
      CrossIsolatesMessage<Uint8List>(
          sender: port.sendPort,
          message: data,
      )
    );
    // 等待回复并返回
    return port.first;
  }

  void onReceivedCommandMsg(CrossIsolatesMessage msg){
    switch (msg.message) {
      case Worker_Isolate_Command.Resume:
        UdpSocketManager().resume();
        break;
      case Worker_Isolate_Command.Suspend:
        UdpSocketManager().suspend();
        break;
      default:
    }
  }

  willSendUdpData(int type, int timeout) async{
    CrossIsolatesMessage msg = CrossIsolatesMessage<int>(
              message: type,
              extra: timeout
          );
    sendPort?.send(msg);
  }
  // 向新 isolate 发送消息并接收回复的方法（发送和接收的数据）
  Future<String> sendReceive(String messageToBeSent) async {
      // 创建一个临时端口来接收回复
      ReceivePort port = ReceivePort();
      // 发送消息到 Isolate，并且通知该 isolate 哪个端口是用来提供回复的
      sendPort?.send(
          CrossIsolatesMessage<String>(
              sender: port.sendPort,
              message: messageToBeSent,
          )
      );
      // 等待回复并返回
      return port.first;
  }
}

// 帮助类
class CrossIsolatesMessage<T> {
    final SendPort sender;
    final T message;
    final dynamic extra;

    CrossIsolatesMessage({
        this.sender,
        @required this.message,
        this.extra
    });
}