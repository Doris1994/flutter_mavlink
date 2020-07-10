/** @file
 *    @brief MAVLink comm protocol testsuite generated from myxml.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef MYXML_TESTSUITE_H
#define MYXML_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_myxml(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_myxml(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_sampledata(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SAMPLEDATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_sampledata_t packet_in = {
        17235,17339,17443,17547,17651,17755,17859,17963,18067,18171
    };
    mavlink_sampledata_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.curr = packet_in.curr;
        packet1.volt = packet_in.volt;
        packet1.temp = packet_in.temp;
        packet1.alit = packet_in.alit;
        packet1.pitch = packet_in.pitch;
        packet1.roll = packet_in.roll;
        packet1.yaw = packet_in.yaw;
        packet1.reserved1 = packet_in.reserved1;
        packet1.reserved2 = packet_in.reserved2;
        packet1.reserved3 = packet_in.reserved3;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SAMPLEDATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SAMPLEDATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sampledata_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_sampledata_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sampledata_pack(system_id, component_id, &msg , packet1.curr , packet1.volt , packet1.temp , packet1.alit , packet1.pitch , packet1.roll , packet1.yaw , packet1.reserved1 , packet1.reserved2 , packet1.reserved3 );
    mavlink_msg_sampledata_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sampledata_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.curr , packet1.volt , packet1.temp , packet1.alit , packet1.pitch , packet1.roll , packet1.yaw , packet1.reserved1 , packet1.reserved2 , packet1.reserved3 );
    mavlink_msg_sampledata_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_sampledata_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sampledata_send(MAVLINK_COMM_1 , packet1.curr , packet1.volt , packet1.temp , packet1.alit , packet1.pitch , packet1.roll , packet1.yaw , packet1.reserved1 , packet1.reserved2 , packet1.reserved3 );
    mavlink_msg_sampledata_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_myxml(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_sampledata(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MYXML_TESTSUITE_H
