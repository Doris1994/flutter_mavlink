/** @file
 *	@brief MAVLink comm testsuite protocol generated from myxml.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "myxml.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(myxml, SAMPLEDATA)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::myxml::msg::SAMPLEDATA packet_in{};
    packet_in.curr = 17235;
    packet_in.volt = 17339;
    packet_in.temp = 17443;
    packet_in.alit = 17547;
    packet_in.pitch = 17651;
    packet_in.roll = 17755;
    packet_in.yaw = 17859;
    packet_in.reserved1 = 17963;
    packet_in.reserved2 = 18067;
    packet_in.reserved3 = 18171;

    mavlink::myxml::msg::SAMPLEDATA packet1{};
    mavlink::myxml::msg::SAMPLEDATA packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.curr, packet2.curr);
    EXPECT_EQ(packet1.volt, packet2.volt);
    EXPECT_EQ(packet1.temp, packet2.temp);
    EXPECT_EQ(packet1.alit, packet2.alit);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.reserved1, packet2.reserved1);
    EXPECT_EQ(packet1.reserved2, packet2.reserved2);
    EXPECT_EQ(packet1.reserved3, packet2.reserved3);
}

#ifdef TEST_INTEROP
TEST(myxml_interop, SAMPLEDATA)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_sampledata_t packet_c {
         17235, 17339, 17443, 17547, 17651, 17755, 17859, 17963, 18067, 18171
    };

    mavlink::myxml::msg::SAMPLEDATA packet_in{};
    packet_in.curr = 17235;
    packet_in.volt = 17339;
    packet_in.temp = 17443;
    packet_in.alit = 17547;
    packet_in.pitch = 17651;
    packet_in.roll = 17755;
    packet_in.yaw = 17859;
    packet_in.reserved1 = 17963;
    packet_in.reserved2 = 18067;
    packet_in.reserved3 = 18171;

    mavlink::myxml::msg::SAMPLEDATA packet2{};

    mavlink_msg_sampledata_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.curr, packet2.curr);
    EXPECT_EQ(packet_in.volt, packet2.volt);
    EXPECT_EQ(packet_in.temp, packet2.temp);
    EXPECT_EQ(packet_in.alit, packet2.alit);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.reserved1, packet2.reserved1);
    EXPECT_EQ(packet_in.reserved2, packet2.reserved2);
    EXPECT_EQ(packet_in.reserved3, packet2.reserved3);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
