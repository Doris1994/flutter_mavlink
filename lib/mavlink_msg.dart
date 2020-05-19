import 'dart:ffi'; // For FFI
//import 'package:ffi/ffi.dart';

const MAVLINK_MSG_ID_HEARTBEAT  = 0;

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

