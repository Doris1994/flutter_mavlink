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
 int16_t remain; /*<  Sample remain*/
 int16_t speed; /*<  Sample speed*/
 int16_t compass; /*<  Sample compass*/
 int16_t status; /*<  Sample status*/
 int16_t reversed1; /*<  Sample reversed1*/
 int16_t reversed2; /*<  Sample reversed2*/
 int16_t reversed3; /*<  Sample reversed3*/
 int16_t reversed4; /*<  Sample reversed4*/
 int16_t reversed5; /*<  Sample reversed5*/
 int16_t reversed6; /*<  Sample reversed6*/
 int16_t reversed7; /*<  Sample reversed7*/
 int16_t reversed8; /*<  Sample reversed8*/
}) mavlink_sampledata_t;

#define MAVLINK_MSG_ID_SAMPLEDATA_LEN 38
#define MAVLINK_MSG_ID_SAMPLEDATA_MIN_LEN 38
#define MAVLINK_MSG_ID_229_LEN 38
#define MAVLINK_MSG_ID_229_MIN_LEN 38

#define MAVLINK_MSG_ID_SAMPLEDATA_CRC 59
#define MAVLINK_MSG_ID_229_CRC 59



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SAMPLEDATA { \
    229, \
    "SAMPLEDATA", \
    19, \
    {  { "curr", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_sampledata_t, curr) }, \
         { "volt", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_sampledata_t, volt) }, \
         { "temp", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_sampledata_t, temp) }, \
         { "alit", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_sampledata_t, alit) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_sampledata_t, pitch) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_sampledata_t, roll) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_sampledata_t, yaw) }, \
         { "remain", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_sampledata_t, remain) }, \
         { "speed", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_sampledata_t, speed) }, \
         { "compass", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_sampledata_t, compass) }, \
         { "status", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_sampledata_t, status) }, \
         { "reversed1", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_sampledata_t, reversed1) }, \
         { "reversed2", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_sampledata_t, reversed2) }, \
         { "reversed3", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_sampledata_t, reversed3) }, \
         { "reversed4", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_sampledata_t, reversed4) }, \
         { "reversed5", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_sampledata_t, reversed5) }, \
         { "reversed6", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_sampledata_t, reversed6) }, \
         { "reversed7", NULL, MAVLINK_TYPE_INT16_T, 0, 34, offsetof(mavlink_sampledata_t, reversed7) }, \
         { "reversed8", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_sampledata_t, reversed8) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SAMPLEDATA { \
    "SAMPLEDATA", \
    19, \
    {  { "curr", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_sampledata_t, curr) }, \
         { "volt", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_sampledata_t, volt) }, \
         { "temp", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_sampledata_t, temp) }, \
         { "alit", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_sampledata_t, alit) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_sampledata_t, pitch) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_sampledata_t, roll) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_sampledata_t, yaw) }, \
         { "remain", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_sampledata_t, remain) }, \
         { "speed", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_sampledata_t, speed) }, \
         { "compass", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_sampledata_t, compass) }, \
         { "status", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_sampledata_t, status) }, \
         { "reversed1", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_sampledata_t, reversed1) }, \
         { "reversed2", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_sampledata_t, reversed2) }, \
         { "reversed3", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_sampledata_t, reversed3) }, \
         { "reversed4", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_sampledata_t, reversed4) }, \
         { "reversed5", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_sampledata_t, reversed5) }, \
         { "reversed6", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_sampledata_t, reversed6) }, \
         { "reversed7", NULL, MAVLINK_TYPE_INT16_T, 0, 34, offsetof(mavlink_sampledata_t, reversed7) }, \
         { "reversed8", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_sampledata_t, reversed8) }, \
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
 * @param remain  Sample remain
 * @param speed  Sample speed
 * @param compass  Sample compass
 * @param status  Sample status
 * @param reversed1  Sample reversed1
 * @param reversed2  Sample reversed2
 * @param reversed3  Sample reversed3
 * @param reversed4  Sample reversed4
 * @param reversed5  Sample reversed5
 * @param reversed6  Sample reversed6
 * @param reversed7  Sample reversed7
 * @param reversed8  Sample reversed8
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sampledata_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t curr, int16_t volt, int16_t temp, int16_t alit, int16_t pitch, int16_t roll, int16_t yaw, int16_t remain, int16_t speed, int16_t compass, int16_t status, int16_t reversed1, int16_t reversed2, int16_t reversed3, int16_t reversed4, int16_t reversed5, int16_t reversed6, int16_t reversed7, int16_t reversed8)
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
    _mav_put_int16_t(buf, 14, remain);
    _mav_put_int16_t(buf, 16, speed);
    _mav_put_int16_t(buf, 18, compass);
    _mav_put_int16_t(buf, 20, status);
    _mav_put_int16_t(buf, 22, reversed1);
    _mav_put_int16_t(buf, 24, reversed2);
    _mav_put_int16_t(buf, 26, reversed3);
    _mav_put_int16_t(buf, 28, reversed4);
    _mav_put_int16_t(buf, 30, reversed5);
    _mav_put_int16_t(buf, 32, reversed6);
    _mav_put_int16_t(buf, 34, reversed7);
    _mav_put_int16_t(buf, 36, reversed8);

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
    packet.remain = remain;
    packet.speed = speed;
    packet.compass = compass;
    packet.status = status;
    packet.reversed1 = reversed1;
    packet.reversed2 = reversed2;
    packet.reversed3 = reversed3;
    packet.reversed4 = reversed4;
    packet.reversed5 = reversed5;
    packet.reversed6 = reversed6;
    packet.reversed7 = reversed7;
    packet.reversed8 = reversed8;

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
 * @param remain  Sample remain
 * @param speed  Sample speed
 * @param compass  Sample compass
 * @param status  Sample status
 * @param reversed1  Sample reversed1
 * @param reversed2  Sample reversed2
 * @param reversed3  Sample reversed3
 * @param reversed4  Sample reversed4
 * @param reversed5  Sample reversed5
 * @param reversed6  Sample reversed6
 * @param reversed7  Sample reversed7
 * @param reversed8  Sample reversed8
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sampledata_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t curr,int16_t volt,int16_t temp,int16_t alit,int16_t pitch,int16_t roll,int16_t yaw,int16_t remain,int16_t speed,int16_t compass,int16_t status,int16_t reversed1,int16_t reversed2,int16_t reversed3,int16_t reversed4,int16_t reversed5,int16_t reversed6,int16_t reversed7,int16_t reversed8)
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
    _mav_put_int16_t(buf, 14, remain);
    _mav_put_int16_t(buf, 16, speed);
    _mav_put_int16_t(buf, 18, compass);
    _mav_put_int16_t(buf, 20, status);
    _mav_put_int16_t(buf, 22, reversed1);
    _mav_put_int16_t(buf, 24, reversed2);
    _mav_put_int16_t(buf, 26, reversed3);
    _mav_put_int16_t(buf, 28, reversed4);
    _mav_put_int16_t(buf, 30, reversed5);
    _mav_put_int16_t(buf, 32, reversed6);
    _mav_put_int16_t(buf, 34, reversed7);
    _mav_put_int16_t(buf, 36, reversed8);

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
    packet.remain = remain;
    packet.speed = speed;
    packet.compass = compass;
    packet.status = status;
    packet.reversed1 = reversed1;
    packet.reversed2 = reversed2;
    packet.reversed3 = reversed3;
    packet.reversed4 = reversed4;
    packet.reversed5 = reversed5;
    packet.reversed6 = reversed6;
    packet.reversed7 = reversed7;
    packet.reversed8 = reversed8;

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
    return mavlink_msg_sampledata_pack(system_id, component_id, msg, sampledata->curr, sampledata->volt, sampledata->temp, sampledata->alit, sampledata->pitch, sampledata->roll, sampledata->yaw, sampledata->remain, sampledata->speed, sampledata->compass, sampledata->status, sampledata->reversed1, sampledata->reversed2, sampledata->reversed3, sampledata->reversed4, sampledata->reversed5, sampledata->reversed6, sampledata->reversed7, sampledata->reversed8);
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
    return mavlink_msg_sampledata_pack_chan(system_id, component_id, chan, msg, sampledata->curr, sampledata->volt, sampledata->temp, sampledata->alit, sampledata->pitch, sampledata->roll, sampledata->yaw, sampledata->remain, sampledata->speed, sampledata->compass, sampledata->status, sampledata->reversed1, sampledata->reversed2, sampledata->reversed3, sampledata->reversed4, sampledata->reversed5, sampledata->reversed6, sampledata->reversed7, sampledata->reversed8);
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
 * @param remain  Sample remain
 * @param speed  Sample speed
 * @param compass  Sample compass
 * @param status  Sample status
 * @param reversed1  Sample reversed1
 * @param reversed2  Sample reversed2
 * @param reversed3  Sample reversed3
 * @param reversed4  Sample reversed4
 * @param reversed5  Sample reversed5
 * @param reversed6  Sample reversed6
 * @param reversed7  Sample reversed7
 * @param reversed8  Sample reversed8
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sampledata_send(mavlink_channel_t chan, int16_t curr, int16_t volt, int16_t temp, int16_t alit, int16_t pitch, int16_t roll, int16_t yaw, int16_t remain, int16_t speed, int16_t compass, int16_t status, int16_t reversed1, int16_t reversed2, int16_t reversed3, int16_t reversed4, int16_t reversed5, int16_t reversed6, int16_t reversed7, int16_t reversed8)
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
    _mav_put_int16_t(buf, 14, remain);
    _mav_put_int16_t(buf, 16, speed);
    _mav_put_int16_t(buf, 18, compass);
    _mav_put_int16_t(buf, 20, status);
    _mav_put_int16_t(buf, 22, reversed1);
    _mav_put_int16_t(buf, 24, reversed2);
    _mav_put_int16_t(buf, 26, reversed3);
    _mav_put_int16_t(buf, 28, reversed4);
    _mav_put_int16_t(buf, 30, reversed5);
    _mav_put_int16_t(buf, 32, reversed6);
    _mav_put_int16_t(buf, 34, reversed7);
    _mav_put_int16_t(buf, 36, reversed8);

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
    packet.remain = remain;
    packet.speed = speed;
    packet.compass = compass;
    packet.status = status;
    packet.reversed1 = reversed1;
    packet.reversed2 = reversed2;
    packet.reversed3 = reversed3;
    packet.reversed4 = reversed4;
    packet.reversed5 = reversed5;
    packet.reversed6 = reversed6;
    packet.reversed7 = reversed7;
    packet.reversed8 = reversed8;

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
    mavlink_msg_sampledata_send(chan, sampledata->curr, sampledata->volt, sampledata->temp, sampledata->alit, sampledata->pitch, sampledata->roll, sampledata->yaw, sampledata->remain, sampledata->speed, sampledata->compass, sampledata->status, sampledata->reversed1, sampledata->reversed2, sampledata->reversed3, sampledata->reversed4, sampledata->reversed5, sampledata->reversed6, sampledata->reversed7, sampledata->reversed8);
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
static inline void mavlink_msg_sampledata_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t curr, int16_t volt, int16_t temp, int16_t alit, int16_t pitch, int16_t roll, int16_t yaw, int16_t remain, int16_t speed, int16_t compass, int16_t status, int16_t reversed1, int16_t reversed2, int16_t reversed3, int16_t reversed4, int16_t reversed5, int16_t reversed6, int16_t reversed7, int16_t reversed8)
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
    _mav_put_int16_t(buf, 14, remain);
    _mav_put_int16_t(buf, 16, speed);
    _mav_put_int16_t(buf, 18, compass);
    _mav_put_int16_t(buf, 20, status);
    _mav_put_int16_t(buf, 22, reversed1);
    _mav_put_int16_t(buf, 24, reversed2);
    _mav_put_int16_t(buf, 26, reversed3);
    _mav_put_int16_t(buf, 28, reversed4);
    _mav_put_int16_t(buf, 30, reversed5);
    _mav_put_int16_t(buf, 32, reversed6);
    _mav_put_int16_t(buf, 34, reversed7);
    _mav_put_int16_t(buf, 36, reversed8);

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
    packet->remain = remain;
    packet->speed = speed;
    packet->compass = compass;
    packet->status = status;
    packet->reversed1 = reversed1;
    packet->reversed2 = reversed2;
    packet->reversed3 = reversed3;
    packet->reversed4 = reversed4;
    packet->reversed5 = reversed5;
    packet->reversed6 = reversed6;
    packet->reversed7 = reversed7;
    packet->reversed8 = reversed8;

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
 * @brief Get field remain from sampledata message
 *
 * @return  Sample remain
 */
static inline int16_t mavlink_msg_sampledata_get_remain(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field speed from sampledata message
 *
 * @return  Sample speed
 */
static inline int16_t mavlink_msg_sampledata_get_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field compass from sampledata message
 *
 * @return  Sample compass
 */
static inline int16_t mavlink_msg_sampledata_get_compass(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field status from sampledata message
 *
 * @return  Sample status
 */
static inline int16_t mavlink_msg_sampledata_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field reversed1 from sampledata message
 *
 * @return  Sample reversed1
 */
static inline int16_t mavlink_msg_sampledata_get_reversed1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field reversed2 from sampledata message
 *
 * @return  Sample reversed2
 */
static inline int16_t mavlink_msg_sampledata_get_reversed2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field reversed3 from sampledata message
 *
 * @return  Sample reversed3
 */
static inline int16_t mavlink_msg_sampledata_get_reversed3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  26);
}

/**
 * @brief Get field reversed4 from sampledata message
 *
 * @return  Sample reversed4
 */
static inline int16_t mavlink_msg_sampledata_get_reversed4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field reversed5 from sampledata message
 *
 * @return  Sample reversed5
 */
static inline int16_t mavlink_msg_sampledata_get_reversed5(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  30);
}

/**
 * @brief Get field reversed6 from sampledata message
 *
 * @return  Sample reversed6
 */
static inline int16_t mavlink_msg_sampledata_get_reversed6(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  32);
}

/**
 * @brief Get field reversed7 from sampledata message
 *
 * @return  Sample reversed7
 */
static inline int16_t mavlink_msg_sampledata_get_reversed7(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  34);
}

/**
 * @brief Get field reversed8 from sampledata message
 *
 * @return  Sample reversed8
 */
static inline int16_t mavlink_msg_sampledata_get_reversed8(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  36);
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
    sampledata->remain = mavlink_msg_sampledata_get_remain(msg);
    sampledata->speed = mavlink_msg_sampledata_get_speed(msg);
    sampledata->compass = mavlink_msg_sampledata_get_compass(msg);
    sampledata->status = mavlink_msg_sampledata_get_status(msg);
    sampledata->reversed1 = mavlink_msg_sampledata_get_reversed1(msg);
    sampledata->reversed2 = mavlink_msg_sampledata_get_reversed2(msg);
    sampledata->reversed3 = mavlink_msg_sampledata_get_reversed3(msg);
    sampledata->reversed4 = mavlink_msg_sampledata_get_reversed4(msg);
    sampledata->reversed5 = mavlink_msg_sampledata_get_reversed5(msg);
    sampledata->reversed6 = mavlink_msg_sampledata_get_reversed6(msg);
    sampledata->reversed7 = mavlink_msg_sampledata_get_reversed7(msg);
    sampledata->reversed8 = mavlink_msg_sampledata_get_reversed8(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SAMPLEDATA_LEN? msg->len : MAVLINK_MSG_ID_SAMPLEDATA_LEN;
        memset(sampledata, 0, MAVLINK_MSG_ID_SAMPLEDATA_LEN);
    memcpy(sampledata, _MAV_PAYLOAD(msg), len);
#endif
}
