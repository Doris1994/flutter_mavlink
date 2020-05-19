import 'dart:async';
import 'package:flutter/services.dart';

import 'dart:ffi'; // For FFI
import 'dart:io'; // For Platform.isX
import 'package:ffi/ffi.dart';
import 'mavlink_msg.dart';

typedef native_add_func = Int32 Function(Int16 x,Int16 y);
typedef NativeAdd = int Function(int x,int y);

final DynamicLibrary flutterMavLinkLib = Platform.isAndroid
    ? DynamicLibrary.open("libflutter_mavlink.so")
    : DynamicLibrary.process();

final nativeAddPointer = 
  flutterMavLinkLib
    .lookup<NativeFunction<native_add_func>>("native_add");
final NativeAdd nativeAdd = nativeAddPointer.asFunction();

final void Function() resetMsgBuffer =  
  flutterMavLinkLib
    .lookup<NativeFunction<Void Function()>>("resetBuffer")
    .asFunction();

final int Function(Pointer<Uint8> buf) encodeHeartBeatMsg =  
  flutterMavLinkLib
    .lookup<NativeFunction<Uint16 Function(Pointer<Uint8> buf)>>("encode_heartbeat_msg")
    .asFunction();

final Pointer<Uint8> Function(Pointer<Uint16> length) encodeHeartBeatMsg2 =  
  flutterMavLinkLib
    .lookup<NativeFunction<Pointer<Uint8> Function(Pointer<Uint16> length)>>("encode_heartbeat_msg2")
    .asFunction();

final Pointer<MavlinkHeartbeat> Function(Pointer<Uint8> buf) decodeMavlinkMsg =  
  flutterMavLinkLib
    .lookup<NativeFunction<Pointer<MavlinkHeartbeat>  Function(Pointer<Uint8> buf)>>("decode_mavlink_msg")
    .asFunction();

final Pointer<MavlinkHeartbeat> Function() decodeHeartbeatMsg =  
  flutterMavLinkLib
    .lookup<NativeFunction<Pointer<MavlinkHeartbeat>  Function()>>("decode_heartbeat_msg")
    .asFunction();


final int Function(Pointer<Uint8> buf) decodeMavlinkMsg2 =  
  flutterMavLinkLib
    .lookup<NativeFunction<Uint16 Function(Pointer<Uint8> buf)>>("decode_mavlink_msg2")
    .asFunction();

int packMavLinkMsgToBuffer(List<int> buf,int type){
    Pointer<Uint8> soureData = allocate<Uint8>(count:buf.length);
    final pointerList = soureData.asTypedList(buf.length);
    pointerList.setAll(0, buf);
    int len;
    switch (type) {
      case 0:
        len = encodeHeartBeatMsg(soureData);
        break;
      default:
    }
    return len;
}

List<int> packMavLinkMsgToBuffer2(int type){
    Pointer<Uint16> lenPointer = allocate();
    Pointer<Uint8> buffer;
    switch (type) {
      case 0:
        buffer = encodeHeartBeatMsg2(lenPointer);;
        break;
      default:
    }
    final pointerList = buffer.asTypedList(lenPointer.value);
    print(pointerList);
    free(lenPointer);
    return pointerList;
}

dynamic getMavLinkMsgFromBuffer(List<int> buf){
    Pointer<Uint8> soureData = allocate<Uint8>(count:buf.length);
    final pointerList = soureData.asTypedList(buf.length);
    pointerList.setAll(0, buf);
    Pointer<MavlinkHeartbeat> msgPointer = decodeMavlinkMsg(soureData);
    final msg = msgPointer.ref;
    free(soureData);
    return msg;
}

int getMavLinkMsgFromBuffer2(List<int> buf){
    Pointer<Uint8> soureData = allocate<Uint8>(count:buf.length);
    final pointerList = soureData.asTypedList(buf.length);
    pointerList.setAll(0, buf);
    return decodeMavlinkMsg2(soureData);
}

class FlutterMavlink {
  static const MethodChannel _channel =
      const MethodChannel('flutter_mavlink');

  static Future<String> get platformVersion async {
    final String version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }
}
