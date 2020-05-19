#pragma once
// MESSAGE KWMM_TEST_MSG PACKING

#define MAVLINK_MSG_ID_KWMM_TEST_MSG 50001

MAVPACKED(
typedef struct __mavlink_kwmm_test_msg_t {
 uint16_t value; /*<  current value*/
}) mavlink_kwmm_test_msg_t;

#define MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN 2
#define MAVLINK_MSG_ID_KWMM_TEST_MSG_MIN_LEN 2
#define MAVLINK_MSG_ID_50001_LEN 2
#define MAVLINK_MSG_ID_50001_MIN_LEN 2

#define MAVLINK_MSG_ID_KWMM_TEST_MSG_CRC 32
#define MAVLINK_MSG_ID_50001_CRC 32



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_KWMM_TEST_MSG { \
    50001, \
    "KWMM_TEST_MSG", \
    1, \
    {  { "value", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_kwmm_test_msg_t, value) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_KWMM_TEST_MSG { \
    "KWMM_TEST_MSG", \
    1, \
    {  { "value", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_kwmm_test_msg_t, value) }, \
         } \
}
#endif

/**
 * @brief Pack a kwmm_test_msg message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param value  current value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_kwmm_test_msg_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN];
    _mav_put_uint16_t(buf, 0, value);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN);
#else
    mavlink_kwmm_test_msg_t packet;
    packet.value = value;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_KWMM_TEST_MSG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_KWMM_TEST_MSG_MIN_LEN, MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN, MAVLINK_MSG_ID_KWMM_TEST_MSG_CRC);
}

/**
 * @brief Pack a kwmm_test_msg message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param value  current value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_kwmm_test_msg_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN];
    _mav_put_uint16_t(buf, 0, value);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN);
#else
    mavlink_kwmm_test_msg_t packet;
    packet.value = value;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_KWMM_TEST_MSG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_KWMM_TEST_MSG_MIN_LEN, MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN, MAVLINK_MSG_ID_KWMM_TEST_MSG_CRC);
}

/**
 * @brief Encode a kwmm_test_msg struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param kwmm_test_msg C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_kwmm_test_msg_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_kwmm_test_msg_t* kwmm_test_msg)
{
    return mavlink_msg_kwmm_test_msg_pack(system_id, component_id, msg, kwmm_test_msg->value);
}

/**
 * @brief Encode a kwmm_test_msg struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param kwmm_test_msg C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_kwmm_test_msg_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_kwmm_test_msg_t* kwmm_test_msg)
{
    return mavlink_msg_kwmm_test_msg_pack_chan(system_id, component_id, chan, msg, kwmm_test_msg->value);
}

/**
 * @brief Send a kwmm_test_msg message
 * @param chan MAVLink channel to send the message
 *
 * @param value  current value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_kwmm_test_msg_send(mavlink_channel_t chan, uint16_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN];
    _mav_put_uint16_t(buf, 0, value);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KWMM_TEST_MSG, buf, MAVLINK_MSG_ID_KWMM_TEST_MSG_MIN_LEN, MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN, MAVLINK_MSG_ID_KWMM_TEST_MSG_CRC);
#else
    mavlink_kwmm_test_msg_t packet;
    packet.value = value;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KWMM_TEST_MSG, (const char *)&packet, MAVLINK_MSG_ID_KWMM_TEST_MSG_MIN_LEN, MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN, MAVLINK_MSG_ID_KWMM_TEST_MSG_CRC);
#endif
}

/**
 * @brief Send a kwmm_test_msg message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_kwmm_test_msg_send_struct(mavlink_channel_t chan, const mavlink_kwmm_test_msg_t* kwmm_test_msg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_kwmm_test_msg_send(chan, kwmm_test_msg->value);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KWMM_TEST_MSG, (const char *)kwmm_test_msg, MAVLINK_MSG_ID_KWMM_TEST_MSG_MIN_LEN, MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN, MAVLINK_MSG_ID_KWMM_TEST_MSG_CRC);
#endif
}

#if MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_kwmm_test_msg_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, value);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KWMM_TEST_MSG, buf, MAVLINK_MSG_ID_KWMM_TEST_MSG_MIN_LEN, MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN, MAVLINK_MSG_ID_KWMM_TEST_MSG_CRC);
#else
    mavlink_kwmm_test_msg_t *packet = (mavlink_kwmm_test_msg_t *)msgbuf;
    packet->value = value;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KWMM_TEST_MSG, (const char *)packet, MAVLINK_MSG_ID_KWMM_TEST_MSG_MIN_LEN, MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN, MAVLINK_MSG_ID_KWMM_TEST_MSG_CRC);
#endif
}
#endif

#endif

// MESSAGE KWMM_TEST_MSG UNPACKING


/**
 * @brief Get field value from kwmm_test_msg message
 *
 * @return  current value
 */
static inline uint16_t mavlink_msg_kwmm_test_msg_get_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a kwmm_test_msg message into a struct
 *
 * @param msg The message to decode
 * @param kwmm_test_msg C-struct to decode the message contents into
 */
static inline void mavlink_msg_kwmm_test_msg_decode(const mavlink_message_t* msg, mavlink_kwmm_test_msg_t* kwmm_test_msg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    kwmm_test_msg->value = mavlink_msg_kwmm_test_msg_get_value(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN? msg->len : MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN;
        memset(kwmm_test_msg, 0, MAVLINK_MSG_ID_KWMM_TEST_MSG_LEN);
    memcpy(kwmm_test_msg, _MAV_PAYLOAD(msg), len);
#endif
}
