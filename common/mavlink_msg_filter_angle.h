#pragma once
// MESSAGE Filter_Angle PACKING

#define MAVLINK_MSG_ID_Filter_Angle 166

MAVPACKED(
typedef struct __mavlink_filter_angle_t {
 uint32_t time_boot_ms; /*<  Timestamp in milliseconds since system boot*/
 float value; /*<  */
 float roll; /*<  */
 float pitch; /*<  */
 float yaw; /*<  */
 float roll_filt; /*<  */
 float pitch_filt; /*<  */
 float yaw_filt; /*<  */
 char name[20]; /*<  */
}) mavlink_filter_angle_t;

#define MAVLINK_MSG_ID_Filter_Angle_LEN 52
#define MAVLINK_MSG_ID_Filter_Angle_MIN_LEN 52
#define MAVLINK_MSG_ID_166_LEN 52
#define MAVLINK_MSG_ID_166_MIN_LEN 52

#define MAVLINK_MSG_ID_Filter_Angle_CRC 156
#define MAVLINK_MSG_ID_166_CRC 156

#define MAVLINK_MSG_Filter_Angle_FIELD_NAME_LEN 20

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_Filter_Angle { \
    166, \
    "Filter_Angle", \
    9, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_filter_angle_t, time_boot_ms) }, \
         { "name", NULL, MAVLINK_TYPE_CHAR, 20, 32, offsetof(mavlink_filter_angle_t, name) }, \
         { "value", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_filter_angle_t, value) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_filter_angle_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_filter_angle_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_filter_angle_t, yaw) }, \
         { "roll_filt", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_filter_angle_t, roll_filt) }, \
         { "pitch_filt", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_filter_angle_t, pitch_filt) }, \
         { "yaw_filt", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_filter_angle_t, yaw_filt) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_Filter_Angle { \
    "Filter_Angle", \
    9, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_filter_angle_t, time_boot_ms) }, \
         { "name", NULL, MAVLINK_TYPE_CHAR, 20, 32, offsetof(mavlink_filter_angle_t, name) }, \
         { "value", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_filter_angle_t, value) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_filter_angle_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_filter_angle_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_filter_angle_t, yaw) }, \
         { "roll_filt", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_filter_angle_t, roll_filt) }, \
         { "pitch_filt", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_filter_angle_t, pitch_filt) }, \
         { "yaw_filt", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_filter_angle_t, yaw_filt) }, \
         } \
}
#endif

/**
 * @brief Pack a filter_angle message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms  Timestamp in milliseconds since system boot
 * @param name  
 * @param value  
 * @param roll  
 * @param pitch  
 * @param yaw  
 * @param roll_filt  
 * @param pitch_filt  
 * @param yaw_filt  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_filter_angle_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, const char *name, float value, float roll, float pitch, float yaw, float roll_filt, float pitch_filt, float yaw_filt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Filter_Angle_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, value);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, roll_filt);
    _mav_put_float(buf, 24, pitch_filt);
    _mav_put_float(buf, 28, yaw_filt);
    _mav_put_char_array(buf, 32, name, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Filter_Angle_LEN);
#else
    mavlink_filter_angle_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.value = value;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.roll_filt = roll_filt;
    packet.pitch_filt = pitch_filt;
    packet.yaw_filt = yaw_filt;
    mav_array_memcpy(packet.name, name, sizeof(char)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Filter_Angle_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_Filter_Angle;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Filter_Angle_MIN_LEN, MAVLINK_MSG_ID_Filter_Angle_LEN, MAVLINK_MSG_ID_Filter_Angle_CRC);
}

/**
 * @brief Pack a filter_angle message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms  Timestamp in milliseconds since system boot
 * @param name  
 * @param value  
 * @param roll  
 * @param pitch  
 * @param yaw  
 * @param roll_filt  
 * @param pitch_filt  
 * @param yaw_filt  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_filter_angle_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,const char *name,float value,float roll,float pitch,float yaw,float roll_filt,float pitch_filt,float yaw_filt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Filter_Angle_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, value);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, roll_filt);
    _mav_put_float(buf, 24, pitch_filt);
    _mav_put_float(buf, 28, yaw_filt);
    _mav_put_char_array(buf, 32, name, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Filter_Angle_LEN);
#else
    mavlink_filter_angle_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.value = value;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.roll_filt = roll_filt;
    packet.pitch_filt = pitch_filt;
    packet.yaw_filt = yaw_filt;
    mav_array_memcpy(packet.name, name, sizeof(char)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Filter_Angle_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_Filter_Angle;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Filter_Angle_MIN_LEN, MAVLINK_MSG_ID_Filter_Angle_LEN, MAVLINK_MSG_ID_Filter_Angle_CRC);
}

/**
 * @brief Encode a filter_angle struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param filter_angle C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_filter_angle_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_filter_angle_t* filter_angle)
{
    return mavlink_msg_filter_angle_pack(system_id, component_id, msg, filter_angle->time_boot_ms, filter_angle->name, filter_angle->value, filter_angle->roll, filter_angle->pitch, filter_angle->yaw, filter_angle->roll_filt, filter_angle->pitch_filt, filter_angle->yaw_filt);
}

/**
 * @brief Encode a filter_angle struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param filter_angle C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_filter_angle_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_filter_angle_t* filter_angle)
{
    return mavlink_msg_filter_angle_pack_chan(system_id, component_id, chan, msg, filter_angle->time_boot_ms, filter_angle->name, filter_angle->value, filter_angle->roll, filter_angle->pitch, filter_angle->yaw, filter_angle->roll_filt, filter_angle->pitch_filt, filter_angle->yaw_filt);
}

/**
 * @brief Send a filter_angle message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms  Timestamp in milliseconds since system boot
 * @param name  
 * @param value  
 * @param roll  
 * @param pitch  
 * @param yaw  
 * @param roll_filt  
 * @param pitch_filt  
 * @param yaw_filt  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_filter_angle_send(mavlink_channel_t chan, uint32_t time_boot_ms, const char *name, float value, float roll, float pitch, float yaw, float roll_filt, float pitch_filt, float yaw_filt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Filter_Angle_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, value);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, roll_filt);
    _mav_put_float(buf, 24, pitch_filt);
    _mav_put_float(buf, 28, yaw_filt);
    _mav_put_char_array(buf, 32, name, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Filter_Angle, buf, MAVLINK_MSG_ID_Filter_Angle_MIN_LEN, MAVLINK_MSG_ID_Filter_Angle_LEN, MAVLINK_MSG_ID_Filter_Angle_CRC);
#else
    mavlink_filter_angle_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.value = value;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.roll_filt = roll_filt;
    packet.pitch_filt = pitch_filt;
    packet.yaw_filt = yaw_filt;
    mav_array_memcpy(packet.name, name, sizeof(char)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Filter_Angle, (const char *)&packet, MAVLINK_MSG_ID_Filter_Angle_MIN_LEN, MAVLINK_MSG_ID_Filter_Angle_LEN, MAVLINK_MSG_ID_Filter_Angle_CRC);
#endif
}

/**
 * @brief Send a filter_angle message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_filter_angle_send_struct(mavlink_channel_t chan, const mavlink_filter_angle_t* filter_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_filter_angle_send(chan, filter_angle->time_boot_ms, filter_angle->name, filter_angle->value, filter_angle->roll, filter_angle->pitch, filter_angle->yaw, filter_angle->roll_filt, filter_angle->pitch_filt, filter_angle->yaw_filt);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Filter_Angle, (const char *)filter_angle, MAVLINK_MSG_ID_Filter_Angle_MIN_LEN, MAVLINK_MSG_ID_Filter_Angle_LEN, MAVLINK_MSG_ID_Filter_Angle_CRC);
#endif
}

#if MAVLINK_MSG_ID_Filter_Angle_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_filter_angle_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, const char *name, float value, float roll, float pitch, float yaw, float roll_filt, float pitch_filt, float yaw_filt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, value);
    _mav_put_float(buf, 8, roll);
    _mav_put_float(buf, 12, pitch);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, roll_filt);
    _mav_put_float(buf, 24, pitch_filt);
    _mav_put_float(buf, 28, yaw_filt);
    _mav_put_char_array(buf, 32, name, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Filter_Angle, buf, MAVLINK_MSG_ID_Filter_Angle_MIN_LEN, MAVLINK_MSG_ID_Filter_Angle_LEN, MAVLINK_MSG_ID_Filter_Angle_CRC);
#else
    mavlink_filter_angle_t *packet = (mavlink_filter_angle_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->value = value;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;
    packet->roll_filt = roll_filt;
    packet->pitch_filt = pitch_filt;
    packet->yaw_filt = yaw_filt;
    mav_array_memcpy(packet->name, name, sizeof(char)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Filter_Angle, (const char *)packet, MAVLINK_MSG_ID_Filter_Angle_MIN_LEN, MAVLINK_MSG_ID_Filter_Angle_LEN, MAVLINK_MSG_ID_Filter_Angle_CRC);
#endif
}
#endif

#endif

// MESSAGE Filter_Angle UNPACKING


/**
 * @brief Get field time_boot_ms from filter_angle message
 *
 * @return  Timestamp in milliseconds since system boot
 */
static inline uint32_t mavlink_msg_filter_angle_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field name from filter_angle message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_filter_angle_get_name(const mavlink_message_t* msg, char *name)
{
    return _MAV_RETURN_char_array(msg, name, 20,  32);
}

/**
 * @brief Get field value from filter_angle message
 *
 * @return  
 */
static inline float mavlink_msg_filter_angle_get_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field roll from filter_angle message
 *
 * @return  
 */
static inline float mavlink_msg_filter_angle_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field pitch from filter_angle message
 *
 * @return  
 */
static inline float mavlink_msg_filter_angle_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field yaw from filter_angle message
 *
 * @return  
 */
static inline float mavlink_msg_filter_angle_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field roll_filt from filter_angle message
 *
 * @return  
 */
static inline float mavlink_msg_filter_angle_get_roll_filt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field pitch_filt from filter_angle message
 *
 * @return  
 */
static inline float mavlink_msg_filter_angle_get_pitch_filt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field yaw_filt from filter_angle message
 *
 * @return  
 */
static inline float mavlink_msg_filter_angle_get_yaw_filt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Decode a filter_angle message into a struct
 *
 * @param msg The message to decode
 * @param filter_angle C-struct to decode the message contents into
 */
static inline void mavlink_msg_filter_angle_decode(const mavlink_message_t* msg, mavlink_filter_angle_t* filter_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    filter_angle->time_boot_ms = mavlink_msg_filter_angle_get_time_boot_ms(msg);
    filter_angle->value = mavlink_msg_filter_angle_get_value(msg);
    filter_angle->roll = mavlink_msg_filter_angle_get_roll(msg);
    filter_angle->pitch = mavlink_msg_filter_angle_get_pitch(msg);
    filter_angle->yaw = mavlink_msg_filter_angle_get_yaw(msg);
    filter_angle->roll_filt = mavlink_msg_filter_angle_get_roll_filt(msg);
    filter_angle->pitch_filt = mavlink_msg_filter_angle_get_pitch_filt(msg);
    filter_angle->yaw_filt = mavlink_msg_filter_angle_get_yaw_filt(msg);
    mavlink_msg_filter_angle_get_name(msg, filter_angle->name);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_Filter_Angle_LEN? msg->len : MAVLINK_MSG_ID_Filter_Angle_LEN;
        memset(filter_angle, 0, MAVLINK_MSG_ID_Filter_Angle_LEN);
    memcpy(filter_angle, _MAV_PAYLOAD(msg), len);
#endif
}
