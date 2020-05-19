import 'dart:async';
import 'dart:io';
import 'dart:ffi'; 

import 'package:connectivity/connectivity.dart';
import 'package:fluttertoast/fluttertoast.dart';
import 'package:flutter_mavlink/flutter_mavlink.dart';
import 'package:flutter_mavlink/mavlink_msg.dart';
import 'package:ffi/ffi.dart';

class UdpSocketManager {
  static UdpSocketManager _instance;
  RawDatagramSocket _udpSocket;
  String _wifiIP;
  Timer _boardCastTimer;//广播定时器
  Map _timeOutMap = {};
  //Map _sendDataMap = {};

  // 工厂模式
  factory UdpSocketManager() =>_getInstance();
  static UdpSocketManager get instance => _getInstance();
  UdpSocketManager._internal() {
    // 初始化
    _initUdp();
  }
  static UdpSocketManager _getInstance() {
    if (_instance == null) {
      _instance = UdpSocketManager._internal();
    }
    return _instance;
  }

  _initUdp() async {
    //InternetAddress.anyIPv4
    await RawDatagramSocket.bind(InternetAddress.anyIPv4, 14551).then((RawDatagramSocket udpSocket) {
      if(udpSocket == null) {
        return; 
      }
      _udpSocket = udpSocket;
      udpSocket.broadcastEnabled = true;
      udpSocket.listen((RawSocketEvent event) {
        if(event == RawSocketEvent.read) {
          Datagram dg = udpSocket.receive();
          _onReceivedData(dg);
        } else if(event == RawSocketEvent.closed) {
          _udpSocket = null;
        } else if(event == RawSocketEvent.write) {
          print('RawSocketEvent.write');
        }
      });
      _boardCast();
    });
  }

  //进入前台，恢复监听
  resume(){
    if(_udpSocket == null){
      _initUdp();
    }
  }
  //进入后台，暂停监听
  suspend(){
    if(_udpSocket != null){
      _udpSocket.close();
    }
    _wifiIP = null;
  }

  sendData( int timeout) async{
    if(_udpSocket == null) {
      print('udp 未初始化');
      return;
    }
    if(_wifiIP == null) {
      _wifiIP = await (Connectivity().getWifiIP());
      if(_wifiIP == null) {
        return;
      }
    }
    List<int> data = packMavLinkMsgToBuffer(0);
    var toAddress = InternetAddress("192.168.1.151");
    _udpSocket.send(data, toAddress, 14550);
  }

  //收到消息
  _onReceivedData(Datagram dg) async {
    if (dg != null) {
      print("received socket data from ${dg.address.address} : ${dg.data}");
      // final msg = getMavLinkMsgFromBuffer(dg.data);
      // if(msg is MavlinkHeartbeat){
      //   print('heartbeat type:${msg.type} base_mode:${msg.base_mode} system_status :${msg.system_status}');
      //   return;
      // }
      int msgId = getMavLinkMsgFromBuffer(dg.data);
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
    }
  }


  //发送广播
  _boardCast() async{
    if(_wifiIP == null) {
      _wifiIP = await (Connectivity().getWifiIP());
      if(_wifiIP == null || _wifiIP == 'error') {
        _wifiIP = '255.255.255.255';
      }
    }
    List<String> array = _wifiIP.split('.');
    array[array.length-1] = '255';
    String destinationIp = array.join('.');
    var destinationAddress = InternetAddress(destinationIp);
    // BoardCastRequestModel requestModel = BoardCastRequestModel();
    // requestModel.toHost = destinationIp;
    // requestModel.fromHost = _wifiIP;
    //List<int> data = SocketDataParser.encodeDataModel(requestModel);  
    List<int> data = packMavLinkMsgToBuffer(0);
    _udpSocket.send(data, destinationAddress, 14550);
  }

}