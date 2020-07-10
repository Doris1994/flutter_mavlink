#pragma once
// MESSAGE SAMPLEDATA PACKING

#define MAVLINK_MSG_ID_SAMPLEDATA 229

MAVPACKED(
typedef struct __mavlink_sampledata_t {
 int16_t curr; /*<  Sample curruet*/
 int16_t volt; /*<  Sample voltage*/
 int16_t temp; /*<  Sample temperature*/
 int16_t alit; /*<  Sample altitude*/
 int16_t pitch; /*<  Sample pitch*/
 int16_t roll; /*<  Sample roll*/
 int16_t yaw; /*<  Sample yaw*/
 int16_t reserved1; /*<  Reserved 1*/
 int16_t reserved2; /*<  Reserved 2*/
 int16_t reserved3; /*<  Reserved 3*/
}) mavlink_sampledata_t;

#define MAVLINK_MSG_ID_SAMPLEDATA_LEN 20
#define MAVLINK_MSG_ID_SAMPLEDATA_MIN_LEN 20
#define MAVLINK_MSG_ID_229_LEN 20
#define MAVLINK_MSG_ID_229_MIN_LEN 20

#define MAVLINK_MSG_ID_SAMPLEDATA_CRC 101
#define MAVLINK_MSG_ID_229_CRC 101



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SAMPLEDATA { \
    229, \
    "SAMPLEDATA", \
    10, \
    {  { "curr", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_sampledata_t, curr) }, \
         { "volt", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_sampledata_t, volt) }, \
         { "temp", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_sampledata_t, temp) }, \
         { "alit", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_sampledata_t, alit) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_sampledata_t, pitch) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_sampledata_t, roll) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_sampledata_t, yaw) }, \
         { "reserved1", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_sampledata_t, reserved1) }, \
         { "reserved2", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_sampledata_t, reserved2) }, \
         { "reserved3", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_sampledata_t, reserved3) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SAMPLEDATA { \
    "SAMPLEDATA", \
    10, \
    {  { "curr", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_sampledata_t, curr) }, \
         { "volt", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_sampledata_t, volt) }, \
         { "temp", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_sampledata_t, temp) }, \
         { "alit", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_sampledata_t, alit) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_sampledata_t, pitch) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_sampledata_t, roll) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_sampledata_t, yaw) }, \
         { "reserved1", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_sampledata_t, reserved1) }, \
         { "reserved2", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_sampledata_t, reserved2) }, \
         { "reserved3", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_sampledata_t, reserved3) }, \
         } \
}
#endif

/**
 * @brief Pack a sampledata message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param curr  Sample curruet
 * @param volt  Sample voltage
 * @param temp  Sample temperature
 * @param alit  Sample altitude
 * @param pitch  Sample pitch
 * @param roll  Sample roll
 * @param yaw  Sample yaw
 * @param reserved1  Reserved 1
 * @param reserved2  Reserved 2
 * @param reserved3  Reserved 3
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sampledata_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t curr, int16_t volt, int16_t temp, int16_t alit, int16_t pitch, int16_t roll, int16_t yaw, int16_t reserved1, int16_t reserved2, int16_t reserved3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SAMPLEDATA_LEN];
    _mav_put_int16_t(buf, 0, curr);
    _mav_put_int16_t(buf, 2, volt);
    _mav_put_int16_t(buf, 4, temp);
    _mav_put_int16_t(buf, 6, alit);
    _mav_put_int16_t(buf, 8, pitch);
    _mav_put_int16_t(buf, 10, roll);
    _mav_put_int16_t(buf, 12, yaw);
    _mav_put_int16_t(buf, 14, reserved1);
    _mav_put_int16_t(buf, 16, reserved2);
    _mav_put_int16_t(buf, 18, reserved3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SAMPLEDATA_LEN);
#else
    mavlink_sampledata_t packet;
    packet.curr = curr;
    packet.volt = volt;
    packet.temp = temp;
    packet.alit = alit;
    packet.pitch = pitch;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.reserved1 = reserved1;
    packet.reserved2 = reserved2;
    packet.reserved3 = reserved3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SAMPLEDATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SAMPLEDATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SAMPLEDATA_MIN_LEN, MAVLINK_MSG_ID_SAMPLEDATA_LEN, MAVLINK_MSG_ID_SAMPLEDATA_CRC);
}

/**
 * @brief Pack a sampledata message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param curr  Sample curruet
 * @param volt  Sample voltage
 * @param temp  Sample temperature
 * @param alit  Sample altitude
 * @param pitch  Sample pitch
 * @param roll  Sample roll
 * @param yaw  Sample yaw
 * @param reserved1  Reserved 1
 * @param reserved2  Reserved 2
 * @param reserved3  Reserved 3
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sampledata_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t curr,int16_t volt,int16_t temp,int16_t alit,int16_t pitch,int16_t roll,int16_t yaw,int16_t reserved1,int16_t reserved2,int16_t reserved3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SAMPLEDATA_LEN];
    _mav_put_int16_t(buf, 0, curr);
    _mav_put_int16_t(buf, 2, volt);
    _mav_put_int16_t(buf, 4, temp);
    _mav_put_int16_t(buf, 6, alit);
    _mav_put_int16_t(buf, 8, pitch);
    _mav_put_int16_t(buf, 10, roll);
    _mav_put_int16_t(buf, 12, yaw);
    _mav_put_int16_t(buf, 14, reserved1);
    _mav_put_int16_t(buf, 16, reserved2);
    _mav_put_int16_t(buf, 18, reserved3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SAMPLEDATA_LEN);
#else
    mavlink_sampledata_t packet;
    packet.curr = curr;
    packet.volt = volt;
    packet.temp = temp;
    packet.alit = alit;
    packet.pitch = pitch;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.reserved1 = reserved1;
    packet.reserved2 = reserved2;
    packet.reserved3 = reserved3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SAMPLEDATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SAMPLEDATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SAMPLEDATA_MIN_LEN, MAVLINK_MSG_ID_SAMPLEDATA_LEN, MAVLINK_MSG_ID_SAMPLEDATA_CRC);
}

/**
 * @brief Encode a sampledata struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sampledata C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sampledata_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sampledata_t* sampledata)
{
    return mavlink_msg_sampledata_pack(system_id, component_id, msg, sampledata->curr, sampledata->volt, sampledata->temp, sampledata->alit, sampledata->pitch, sampledata->roll, sampledata->yaw, sampledata->reserved1, sampledata->reserved2, sampledata->reserved3);
}

/**
 * @brief Encode a sampledata struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sampledata C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sampledata_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sampledata_t* sampledata)
{
    return mavlink_msg_sampledata_pack_chan(system_id, component_id, chan, msg, sampledata->curr, sampledata->volt, sampledata->temp, sampledata->alit, sampledata->pitch, sampledata->roll, sampledata->yaw, sampledata->reserved1, sampledata->reserved2, sampledata->reserved3);
}

/**
 * @brief Send a sampledata message
 * @param chan MAVLink channel to send the message
 *
 * @param curr  Sample curruet
 * @param volt  Sample voltage
 * @param temp  Sample temperature
 * @param alit  Sample altitude
 * @param pitch  Sample pitch
 * @param roll  Sample roll
 * @param yaw  Sample yaw
 * @param reserved1  Reserved 1
 * @param reserved2  Reserved 2
 * @param reserved3  Reserved 3
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sampledata_send(mavlink_channel_t chan, int16_t curr, int16_t volt, int16_t temp, int16_t alit, int16_t pitch, int16_t roll, int16_t yaw, int16_t reserved1, int16_t reserved2, int16_t reserved3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SAMPLEDATA_LEN];
    _mav_put_int16_t(buf, 0, curr);
    _mav_put_int16_t(buf, 2, volt);
    _mav_put_int16_t(buf, 4, temp);
    _mav_put_int16_t(buf, 6, alit);
    _mav_put_int16_t(buf, 8, pitch);
    _mav_put_int16_t(buf, 10, roll);
    _mav_put_int16_t(buf, 12, yaw);
    _mav_put_int16_t(buf, 14, reserved1);
    _mav_put_int16_t(buf, 16, reserved2);
    _mav_put_int16_t(buf, 18, reserved3);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SAMPLEDATA, buf, MAVLINK_MSG_ID_SAMPLEDATA_MIN_LEN, MAVLINK_MSG_ID_SAMPLEDATA_LEN, MAVLINK_MSG_ID_SAMPLEDATA_CRC);
#else
    mavlink_sampledata_t packet;
    packet.curr = curr;
    packet.volt = volt;
    packet.temp = temp;
    packet.alit = alit;
    packet.pitch = pitch;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.reserved1 = reserved1;
    packet.reserved2 = reserved2;
    packet.reserved3 = reserved3;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SAMPLEDATA, (const char *)&packet, MAVLINK_MSG_ID_SAMPLEDATA_MIN_LEN, MAVLINK_MSG_ID_SAMPLEDATA_LEN, MAVLINK_MSG_ID_SAMPLEDATA_CRC);
#endif
}

/**
 * @brief Send a sampledata message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sampledata_send_struct(mavlink_channel_t chan, const mavlink_sampledata_t* sampledata)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sampledata_send(chan, sampledata->curr, sampledata->volt, sampledata->temp, sampledata->alit, sampledata->pitch, sampledata->roll, sampledata->yaw, sampledata->reserved1, sampledata->reserved2, sampledata->reserved3);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SAMPLEDATA, (const char *)sampledata, MAVLINK_MSG_ID_SAMPLEDATA_MIN_LEN, MAVLINK_MSG_ID_SAMPLEDATA_LEN, MAVLINK_MSG_ID_SAMPLEDATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_SAMPLEDATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sampledata_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t curr, int16_t volt, int16_t temp, int16_t alit, int16_t pitch, int16_t roll, int16_t yaw, int16_t reserved1, int16_t reserved2, int16_t reserved3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, curr);
    _mav_put_int16_t(buf, 2, volt);
    _mav_put_int16_t(buf, 4, temp);
    _mav_put_int16_t(buf, 6, alit);
    _mav_put_int16_t(buf, 8, pitch);
    _mav_put_int16_t(buf, 10, roll);
    _mav_put_int16_t(buf, 12, yaw);
    _mav_put_int16_t(buf, 14, reserved1);
    _mav_put_int16_t(buf, 16, reserved2);
    _mav_put_int16_t(buf, 18, reserved3);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SAMPLEDATA, buf, MAVLINK_MSG_ID_SAMPLEDATA_MIN_LEN, MAVLINK_MSG_ID_SAMPLEDATA_LEN, MAVLINK_MSG_ID_SAMPLEDATA_CRC);
#else
    mavlink_sampledata_t *packet = (mavlink_sampledata_t *)msgbuf;
    packet->curr = curr;
    packet->volt = volt;
    packet->temp = temp;
    packet->alit = alit;
    packet->pitch = pitch;
    packet->roll = roll;
    packet->yaw = yaw;
    packet->reserved1 = reserved1;
    packet->reserved2 = reserved2;
    packet->reserved3 = reserved3;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SAMPLEDATA, (const char *)packet, MAVLINK_MSG_ID_SAMPLEDATA_MIN_LEN, MAVLINK_MSG_ID_SAMPLEDATA_LEN, MAVLINK_MSG_ID_SAMPLEDATA_CRC);
#endif
}
#endif

#endif

// MESSAGE SAMPLEDATA UNPACKING


/**
 * @brief Get field curr from sampledata message
 *
 * @return  Sample curruet
 */
static inline int16_t mavlink_msg_sampledata_get_curr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field volt from sampledata message
 *
 * @return  Sample voltage
 */
static inline int16_t mavlink_msg_sampledata_get_volt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field temp from sampledata message
 *
 * @return  Sample temperature
 */
static inline int16_t mavlink_msg_sampledata_get_temp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field alit from sampledata message
 *
 * @return  Sample altitude
 */
static inline int16_t mavlink_msg_sampledata_get_alit(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field pitch from sampledata message
 *
 * @return  Sample pitch
 */
static inline int16_t mavlink_msg_sampledata_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field roll from sampledata message
 *
 * @return  Sample roll
 */
static inline int16_t mavlink_msg_sampledata_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field yaw from sampledata message
 *
 * @return  Sample yaw
 */
static inline int16_t mavlink_msg_sampledata_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field reserved1 from sampledata message
 *
 * @return  Reserved 1
 */
static inline int16_t mavlink_msg_sampledata_get_reserved1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field reserved2 from sampledata message
 *
 * @return  Reserved 2
 */
static inline int16_t mavlink_msg_sampledata_get_reserved2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field reserved3 from sampledata message
 *
 * @return  Reserved 3
 */
static inline int16_t mavlink_msg_sampledata_get_reserved3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Decode a sampledata message into a struct
 *
 * @param msg The message to decode
 * @param sampledata C-struct to decode the message contents into
 */
static inline void mavlink_msg_sampledata_decode(const mavlink_message_t* msg, mavlink_sampledata_t* sampledata)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sampledata->curr = mavlink_msg_sampledata_get_curr(msg);
    sampledata->volt = mavlink_msg_sampledata_get_volt(msg);
    sampledata->temp = mavlink_msg_sampledata_get_temp(msg);
    sampledata->alit = mavlink_msg_sampledata_get_alit(msg);
    sampledata->pitch = mavlink_msg_sampledata_get_pitch(msg);
    sampledata->roll = mavlink_msg_sampledata_get_roll(msg);
    sampledata->yaw = mavlink_msg_sampledata_get_yaw(msg);
    sampledata->reserved1 = mavlink_msg_sampledata_get_reserved1(msg);
    sampledata->reserved2 = mavlink_msg_sampledata_get_reserved2(msg);
    sampledata->reserved3 = mavlink_msg_sampledata_get_reserved3(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SAMPLEDATA_LEN? msg->len : MAVLINK_MSG_ID_SAMPLEDATA_LEN;
        memset(sampledata, 0, MAVLINK_MSG_ID_SAMPLEDATA_LEN);
    memcpy(sampledata, _MAV_PAYLOAD(msg), len);
#endif
}
