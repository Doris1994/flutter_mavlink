/** @file
 *	@brief MAVLink comm testsuite protocol generated from custom_msg.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "custom_msg.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(custom_msg, KWMM_TEST_MSG)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::custom_msg::msg::KWMM_TEST_MSG packet_in{};
    packet_in.value = 17235;

    mavlink::custom_msg::msg::KWMM_TEST_MSG packet1{};
    mavlink::custom_msg::msg::KWMM_TEST_MSG packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.value, packet2.value);
}

#ifdef TEST_INTEROP
TEST(custom_msg_interop, KWMM_TEST_MSG)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_kwmm_test_msg_t packet_c {
         17235
    };

    mavlink::custom_msg::msg::KWMM_TEST_MSG packet_in{};
    packet_in.value = 17235;

    mavlink::custom_msg::msg::KWMM_TEST_MSG packet2{};

    mavlink_msg_kwmm_test_msg_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.value, packet2.value);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
