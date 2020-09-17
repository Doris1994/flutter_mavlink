import 'dart:async';
import 'dart:typed_data';
import 'package:flutter/services.dart';

import 'dart:ffi'; // For FFI
import 'dart:io'; // For Platform.isX
import 'package:ffi/ffi.dart';
import 'mavlink_msg.dart';

typedef native_add_func = Int32 Function(Int16 x, Int16 y);
typedef NativeAddFunction = int Function(int x, int y);

typedef native_encode_manual_control_msg_func = Pointer<Uint8> Function(
    Pointer<Uint16> length,
    Uint16 x,
    Uint16 y,
    Uint16 z,
    Uint16 r,
    Uint16 buttons);
typedef NativeEncodeManualControlMsgFunc = Pointer<Uint8> Function(
    Pointer<Uint16> length, int x, int y, int z, int r, int buttons);

final DynamicLibrary flutterMavLinkLib = Platform.isAndroid
    ? DynamicLibrary.open("libflutter_mavlink.so")
    : DynamicLibrary.process();

final nativeAddPointer =
    flutterMavLinkLib.lookup<NativeFunction<native_add_func>>("native_add");
final NativeAddFunction nativeAdd = nativeAddPointer.asFunction();

final void Function() resetMsgBuffer = flutterMavLinkLib
    .lookup<NativeFunction<Void Function()>>("resetBuffer")
    .asFunction();

final Pointer<Uint8> Function(
    Pointer<Uint16>
        length) encodeHeartBeatMsg = flutterMavLinkLib
    .lookup<NativeFunction<Pointer<Uint8> Function(Pointer<Uint16> length)>>(
        "encode_heartbeat_msg")
    .asFunction();

final Pointer<MavlinkHeartbeat> Function() decodeHeartbeatMsg =
    flutterMavLinkLib
        .lookup<NativeFunction<Pointer<MavlinkHeartbeat> Function()>>(
            "decode_heartbeat_msg")
        .asFunction();

final NativeEncodeManualControlMsgFunc encodeManualControlMsg =
    flutterMavLinkLib
        .lookup<NativeFunction<native_encode_manual_control_msg_func>>(
            "encode_manual_control_msg")
        .asFunction();

final Pointer<MavlinkManualControl> Function() decodeManualControlMsg =
    flutterMavLinkLib
        .lookup<NativeFunction<Pointer<MavlinkManualControl> Function()>>(
            "decode_manual_control_msg")
        .asFunction();

final Pointer<MavlinkSampleData> Function() decodeSampleDataMsg =
    flutterMavLinkLib
        .lookup<NativeFunction<Pointer<MavlinkSampleData> Function()>>(
            "decode_sampledata_msg")
        .asFunction();

final int Function(Pointer<Uint8> buf) decodeMavlinkMsg = flutterMavLinkLib
    .lookup<NativeFunction<Int64 Function(Pointer<Uint8> buf)>>(
        "decode_mavlink_msg")
    .asFunction();

final int Function(int temp, int newMsg) parseMavlinkMsgChar = flutterMavLinkLib
    .lookup<NativeFunction<Int64 Function(Uint8 temp, Uint8 newMsg)>>(
        "parse_mavlink_char")
    .asFunction();

List<int> packMavLinkMsgToBuffer(int type, Struct msg) {
  resetMsgBuffer();
  Pointer<Uint16> lenPointer = allocate();
  Pointer<Uint8> buffer;
  switch (type) {
    case MAVLINK_MSG_ID_HEARTBEAT:
      buffer = encodeHeartBeatMsg(lenPointer);
      break;
    case MAVLINK_MSG_ID_MANUAL_CONTROL:
      {
        MavlinkManualControl manualControl = msg;
        if (msg == null) {
          return null;
        }
        /*print(
            '======= MAVLINK_MSG_ID_MANUAL_CONTROL=======  x:${manualControl.x} y:${manualControl.y} z:${manualControl.z} r:${manualControl.r} buttons:${manualControl.buttons}');*/
        buffer = encodeManualControlMsg(
            lenPointer,
            manualControl.x,
            manualControl.y,
            manualControl.z,
            manualControl.r,
            manualControl.buttons);
      }
      break;
    default:
      return null;
  }
  final pointerList = buffer.asTypedList(lenPointer.value);
  //print('packMavLinkMsgToBuffer result: $pointerList');
  free(lenPointer);
  return pointerList;
}

int getMavLinkMsgFromBuffer(List<int> buf) {
  Pointer<Uint8> mavlinkSoureData = allocate<Uint8>(count: buf.length);
  final pointerList = mavlinkSoureData.asTypedList(buf.length);
  pointerList.setAll(0, buf);
  int msgId = decodeMavlinkMsg(mavlinkSoureData);
  free(mavlinkSoureData);
  return msgId;
}

class FlutterMavlink {
  static const MethodChannel _channel = const MethodChannel('flutter_mavlink');

  static Future<String> get platformVersion async {
    final String version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }
}
