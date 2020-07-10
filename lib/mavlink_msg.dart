import 'dart:ffi';

import 'package:ffi/ffi.dart'; // For FFI
//import 'package:ffi/ffi.dart';

const MAVLINK_MSG_ID_HEARTBEAT = 0;

const MAVLINK_MSG_ID_MANUAL_CONTROL = 69;

const MAVLINK_MSG_ID_SAMPLEDATA = 229;

class MavlinkManualControlButtons {
  static const int unLock = 32;
  static const int lock = 16;

  static const int manualMode = 1; //手动模式
  static const int selfStableMode = 8; //自稳模式
  static const int keepDepthMode = 4; //定深模式

  static const int effluentMode = 64; //出水模式

  static const int increaseLeftBrightness = 128;
  static const int decreaseLeftBrightness = 256;
  static const int increaseRightBrightness = 512;
  static const int decreaseRightBrightness = 1024;

  /*static const int increaseRoll = 44;
  static const int decreaseRoll = 45;
  static const int increasePitch = 46;
  static const int decreasePitch = 47;

  static const int keepInput = 48; //输入保持*/
  static const int controlModeSwitch = 2048; //切换姿态控制模式或运动控制模式
}

// Example of handling a simple C struct mavlink_heartbeat_t
class MavlinkHeartbeat extends Struct {
  @Uint32()
  int custom_mode;

  @Uint8()
  int type;

  @Uint8()
  int autopilot;

  @Uint8()
  int base_mode;

  @Uint8()
  int system_status;

  @Uint8()
  int mavlink_version;

  // factory MavlinkHeartbeat.allocate(@Uint32() custom_mode, @Uint8() type,@Uint8() autopilot, @Uint8() base_mode,@Uint8() system_status, @Uint8() mavlink_version) =>
  //     allocate<MavlinkHeartbeat>().ref
  //       ..custom_mode = custom_mode
  //       ..type = type
  //       ..autopilot  = autopilot
  //       ..base_mode = base_mode
  //       ..system_status = system_status
  //       ..mavlink_version = mavlink_version;
}

class MavlinkManualControl extends Struct {
  @Int16()
  int x;

  @Int16()
  int y;

  @Int16()
  int z;

  @Int16()
  int r;

  @Uint16()
  int buttons;

  @Uint8()
  int target;

  factory MavlinkManualControl.allocate(
    @Int16() x,
    @Int16() y,
    @Int16() z,
    @Int16() r,
    @Uint16() buttons,
  ) =>
      allocate<MavlinkManualControl>().ref
        ..x = x
        ..y = y
        ..z = z
        ..r = r
        ..buttons = buttons;
}

class MavlinkSampleData extends Struct {
  @Int16()
  int curr;

  @Int16()
  int volt;

  @Int16()
  int temp;

  @Int16()
  int alit;

  @Int16()
  int pitch;

  @Int16()
  int roll;

  @Int16()
  int yaw;

  @Int16()
  int reserved1;

  @Int16()
  int reserved2;

  @Int16()
  int reserved3;
}
