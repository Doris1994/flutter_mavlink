#include <stdint.h>
#include <stdlib.h>
//#include "flutter_mavlink.h"
#include "mavlink/myxml/mavlink.h"

#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)

uint8_t buffer[BUFFER_LENGTH];
mavlink_message_t *msg = nullptr;

mavlink_system_t mavlink_system = {
   255, // System ID (1-255)253
   MAV_COMP_ID_MISSIONPLANNER  // Component ID (a MAV_COMPONENT value)MAV_COMP_ID_MISSIONPLANNER
};
// typedef struct {
//   uint8_t *buffer;
//   uint16_t length;
// } kw_mavlink_msg_buf_t;
extern "C" {
  __attribute__((visibility("default"))) __attribute__((used))

  void resetBuffer() {
    memset(buffer, 0, BUFFER_LENGTH);
  }

  int32_t native_add(int16_t x, int16_t y) { return  x + y; }

  //---------------------心跳包------------------------
  uint8_t* encode_heartbeat_msg(int16_t *length){
    mavlink_message_t temp_msg;
    /*Send Heartbeat */
    mavlink_msg_heartbeat_pack(mavlink_system.sysid, mavlink_system.compid, &temp_msg, MAV_TYPE_GCS, MAV_AUTOPILOT_INVALID, MAV_MODE_MANUAL_ARMED, 0, MAV_STATE_ACTIVE);
    *length = mavlink_msg_to_send_buffer(buffer, &temp_msg);
    return buffer;
  }

  mavlink_heartbeat_t* decode_heartbeat_msg(){
    // Get all fields in payload (into heartbeat)
    mavlink_heartbeat_t *heartbeat = (mavlink_heartbeat_t *)malloc(sizeof(mavlink_heartbeat_t));
    mavlink_msg_heartbeat_decode(msg, heartbeat);
    return heartbeat;
  }

  //---------------------手动控制------------------------
  uint8_t* encode_manual_control_msg(int16_t *length,int16_t x, int16_t y,int16_t z, int16_t r,int16_t buttons){
    mavlink_message_t temp_msg;
    mavlink_msg_manual_control_pack(mavlink_system.sysid, mavlink_system.compid,&temp_msg,1,x,y,z,r,buttons);
    *length = mavlink_msg_to_send_buffer(buffer, &temp_msg);
    return buffer;
  }

  mavlink_manual_control_t* decode_manual_control_msg(){
    // Get all fields in payload (into manual_control)
    mavlink_manual_control_t *manual_control = (mavlink_manual_control_t *)malloc(sizeof(mavlink_manual_control_t));
    mavlink_msg_manual_control_decode(msg, manual_control);
    return manual_control;
  }

  mavlink_sampledata_t* decode_sampledata_msg(){
    // Get all fields in payload (into manual_control)
    mavlink_sampledata_t *sample_data = (mavlink_sampledata_t *)malloc(sizeof(mavlink_sampledata_t));
    mavlink_msg_sampledata_decode(msg,sample_data);
    return sample_data;
  }

  int64_t decode_mavlink_msg(uint8_t *buf,uint16_t len
  ){
    if(len > 0){
      // Something received - print out all bytes and parse packet
      unsigned int temp = 0;
      if(msg == nullptr){
        msg = (mavlink_message_t *)malloc(sizeof(mavlink_message_t));
        //free(msg);
      } else {
        memset(msg, 0, sizeof(mavlink_message_t));
      }
      mavlink_status_t status;
      for (int i = 0; i < len; ++i) {
        temp = buf[i];
        if (mavlink_parse_char(MAVLINK_COMM_0, temp, msg, &status)) {
          // Packet received
          //printf("\nReceived packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n", msg.sysid, msg.compid, msg.len, msg.msgid);
          return (*msg).msgid;
        }
      }
    }
    return -1;
  }
}
