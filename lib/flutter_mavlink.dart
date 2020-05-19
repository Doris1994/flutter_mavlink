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

final Pointer<Uint8> Function(Pointer<Uint16> length) encodeHeartBeatMsg =  
  flutterMavLinkLib
    .lookup<NativeFunction<Pointer<Uint8> Function(Pointer<Uint16> length)>>("encode_heartbeat_msg")
    .asFunction();

final Pointer<MavlinkHeartbeat> Function() decodeHeartbeatMsg =  
  flutterMavLinkLib
    .lookup<NativeFunction<Pointer<MavlinkHeartbeat>  Function()>>("decode_heartbeat_msg")
    .asFunction();

final int Function(Pointer<Uint8> buf) decodeMavlinkMsg =  
  flutterMavLinkLib
    .lookup<NativeFunction<Uint16 Function(Pointer<Uint8> buf)>>("decode_mavlink_msg")
    .asFunction();

List<int> packMavLinkMsgToBuffer(int type){
    Pointer<Uint16> lenPointer = allocate();
    Pointer<Uint8> buffer;
    switch (type) {
      case 0:
        buffer = encodeHeartBeatMsg(lenPointer);
        break;
      default:
    }
    final pointerList = buffer.asTypedList(lenPointer.value);
    print('packMavLinkMsgToBuffer result: $pointerList');
    free(lenPointer);
    resetMsgBuffer();
    return pointerList;
}

int getMavLinkMsgFromBuffer(List<int> buf){
    Pointer<Uint8> soureData = allocate<Uint8>(count:buf.length);
    final pointerList = soureData.asTypedList(buf.length);
    pointerList.setAll(0, buf);
    return decodeMavlinkMsg(soureData);
}

class FlutterMavlink {
  static const MethodChannel _channel =
      const MethodChannel('flutter_mavlink');

  static Future<String> get platformVersion async {
    final String version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }
}
