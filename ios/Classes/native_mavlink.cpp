#include <stdint.h>
#include <stdlib.h>
#include "mavlink/custom_msg/mavlink.h"

#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)

int32_t z = 0;
uint8_t buffer[BUFFER_LENGTH];
mavlink_message_t msg;
mavlink_status_t status;

mavlink_system_t mavlink_system = {
   253, // System ID (1-255)253
   MAV_COMP_ID_MISSIONPLANNER  // Component ID (a MAV_COMPONENT value)MAV_COMP_ID_MISSIONPLANNER
};

typedef struct {
  uint8_t *buffer;
  uint16_t length;
} kw_mavlink_msg_buf_t;

typedef struct {
  
} kw_mavlink_msg_t;

extern "C" {

   __attribute__((visibility("default"))) __attribute__((used))
  void resetBuffer()
  {
    memset(buffer, 0, BUFFER_LENGTH);
  }

  int32_t native_add(int16_t x, int16_t y) { z = z + x + y;return z; }

  uint16_t encode_heartbeat_msg(uint8_t *buf){
    mavlink_message_t temp_msg;
    uint16_t len;
    /*Send Heartbeat */
    mavlink_msg_heartbeat_pack(1, 200, &temp_msg, MAV_TYPE_HELICOPTER, MAV_AUTOPILOT_GENERIC, MAV_MODE_GUIDED_ARMED, 0, MAV_STATE_ACTIVE);
    len = mavlink_msg_to_send_buffer(buf, &temp_msg);
    return len;
  }

  uint8_t* encode_heartbeat_msg2(int16_t *length){
    resetBuffer();
    mavlink_message_t temp_msg;
    /*Send Heartbeat */
    mavlink_msg_heartbeat_pack(1, 200, &temp_msg, MAV_TYPE_HELICOPTER, MAV_AUTOPILOT_GENERIC, MAV_MODE_GUIDED_ARMED, 0, MAV_STATE_ACTIVE);
    *length = mavlink_msg_to_send_buffer(buffer, &temp_msg);
    return buffer;
  }

  mavlink_heartbeat_t* decode_mavlink_msg(uint8_t *buf,uint16_t len
  ){
    if(len > 0){
      	// Something received - print out all bytes and parse packet
			mavlink_message_t temp_msg;
			mavlink_status_t status;
			unsigned int temp = 0;
			//printf("Bytes Received: %d\nDatagram: ", (int)recsize);
			for (int i = 0; i < len; ++i)
			{
				temp = buf[i];
				if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &temp_msg, &status))
				{
					// Packet received
					printf("\nReceived packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d\n", temp_msg.sysid, temp_msg.compid, temp_msg.len, temp_msg.msgid);
          switch(temp_msg.msgid) {
            case MAVLINK_MSG_ID_HEARTBEAT:
              {
                // Get all fields in payload (into heartbeat)
                mavlink_heartbeat_t *heartbeat = (mavlink_heartbeat_t *)malloc(sizeof(mavlink_heartbeat_t));
                //mavlink_heartbeat_t heartbeat;
                mavlink_msg_heartbeat_decode(&temp_msg, heartbeat);
                return heartbeat;
              }
              break;
              case MAVLINK_MSG_ID_KWMM_TEST_MSG:
                {
                  // Get just one field from payload
                  uint16_t value = mavlink_msg_kwmm_test_msg_get_value(&temp_msg);
                  
                }
                break;
              case MAVLINK_MSG_ID_COMMAND_INT:{
                mavlink_command_int_t command_int;
                mavlink_msg_command_int_decode(&temp_msg,&command_int);
              } break;
              case MAVLINK_MSG_ID_COMMAND_LONG:{
                mavlink_command_long_t command_long;
                mavlink_msg_command_long_decode(&temp_msg,&command_long);
              } break;
              default:
                break;
          }

				}
			}
    }
  }
 
  mavlink_heartbeat_t* decode_heartbeat_msg(){
    // Get all fields in payload (into heartbeat)
    mavlink_heartbeat_t *heartbeat = (mavlink_heartbeat_t *)malloc(sizeof(mavlink_heartbeat_t));
    mavlink_msg_heartbeat_decode(&msg, heartbeat);
    return heartbeat;
  }

  uint16_t decode_mavlink_msg2(uint8_t *buf,uint16_t len
  ){
    if(len > 0){
      	// Something received - print out all bytes and parse packet
			unsigned int temp = 0;
			printf("Bytes Received: %d\nDatagram: ", (int)len);
			for (int i = 0; i < len; ++i)
			{
				temp = buf[i];
				if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &msg, &status))
				{
          return msg.msgid;
				}
			}
    }
  }
}