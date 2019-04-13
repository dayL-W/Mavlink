#pragma once
// MESSAGE Filter_Angle PACKING

#define MAVLINK_MSG_ID_Filter_Angle 166

MAVPACKED(
typedef struct __mavlink_filter_angle_t {
 uint64_t timestamp; /*<  Timestamp in milliseconds since system boot*/
 uint64_t value; /*<  */
 char key[20]; /*<  */
}) mavlink_filter_angle_t;

#define MAVLINK_MSG_ID_Filter_Angle_LEN 36
#define MAVLINK_MSG_ID_Filter_Angle_MIN_LEN 36
#define MAVLINK_MSG_ID_166_LEN 36
#define MAVLINK_MSG_ID_166_MIN_LEN 36

#define MAVLINK_MSG_ID_Filter_Angle_CRC 106
#define MAVLINK_MSG_ID_166_CRC 106

#define MAVLINK_MSG_Filter_Angle_FIELD_KEY_LEN 20

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_Filter_Angle { \
    166, \
    "Filter_Angle", \
    3, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_filter_angle_t, timestamp) }, \
         { "key", NULL, MAVLINK_TYPE_CHAR, 20, 16, offsetof(mavlink_filter_angle_t, key) }, \
         { "value", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_filter_angle_t, value) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_Filter_Angle { \
    "Filter_Angle", \
    3, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_filter_angle_t, timestamp) }, \
         { "key", NULL, MAVLINK_TYPE_CHAR, 20, 16, offsetof(mavlink_filter_angle_t, key) }, \
         { "value", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_filter_angle_t, value) }, \
         } \
}
#endif

/**
 * @brief Pack a filter_angle message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  Timestamp in milliseconds since system boot
 * @param key  
 * @param value  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_filter_angle_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, const char *key, uint64_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Filter_Angle_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint64_t(buf, 8, value);
    _mav_put_char_array(buf, 16, key, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Filter_Angle_LEN);
#else
    mavlink_filter_angle_t packet;
    packet.timestamp = timestamp;
    packet.value = value;
    mav_array_memcpy(packet.key, key, sizeof(char)*20);
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
 * @param timestamp  Timestamp in milliseconds since system boot
 * @param key  
 * @param value  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_filter_angle_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,const char *key,uint64_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Filter_Angle_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint64_t(buf, 8, value);
    _mav_put_char_array(buf, 16, key, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Filter_Angle_LEN);
#else
    mavlink_filter_angle_t packet;
    packet.timestamp = timestamp;
    packet.value = value;
    mav_array_memcpy(packet.key, key, sizeof(char)*20);
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
    return mavlink_msg_filter_angle_pack(system_id, component_id, msg, filter_angle->timestamp, filter_angle->key, filter_angle->value);
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
    return mavlink_msg_filter_angle_pack_chan(system_id, component_id, chan, msg, filter_angle->timestamp, filter_angle->key, filter_angle->value);
}

/**
 * @brief Send a filter_angle message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  Timestamp in milliseconds since system boot
 * @param key  
 * @param value  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_filter_angle_send(mavlink_channel_t chan, uint64_t timestamp, const char *key, uint64_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_Filter_Angle_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint64_t(buf, 8, value);
    _mav_put_char_array(buf, 16, key, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Filter_Angle, buf, MAVLINK_MSG_ID_Filter_Angle_MIN_LEN, MAVLINK_MSG_ID_Filter_Angle_LEN, MAVLINK_MSG_ID_Filter_Angle_CRC);
#else
    mavlink_filter_angle_t packet;
    packet.timestamp = timestamp;
    packet.value = value;
    mav_array_memcpy(packet.key, key, sizeof(char)*20);
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
    mavlink_msg_filter_angle_send(chan, filter_angle->timestamp, filter_angle->key, filter_angle->value);
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
static inline void mavlink_msg_filter_angle_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, const char *key, uint64_t value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint64_t(buf, 8, value);
    _mav_put_char_array(buf, 16, key, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Filter_Angle, buf, MAVLINK_MSG_ID_Filter_Angle_MIN_LEN, MAVLINK_MSG_ID_Filter_Angle_LEN, MAVLINK_MSG_ID_Filter_Angle_CRC);
#else
    mavlink_filter_angle_t *packet = (mavlink_filter_angle_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->value = value;
    mav_array_memcpy(packet->key, key, sizeof(char)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Filter_Angle, (const char *)packet, MAVLINK_MSG_ID_Filter_Angle_MIN_LEN, MAVLINK_MSG_ID_Filter_Angle_LEN, MAVLINK_MSG_ID_Filter_Angle_CRC);
#endif
}
#endif

#endif

// MESSAGE Filter_Angle UNPACKING


/**
 * @brief Get field timestamp from filter_angle message
 *
 * @return  Timestamp in milliseconds since system boot
 */
static inline uint64_t mavlink_msg_filter_angle_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field key from filter_angle message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_filter_angle_get_key(const mavlink_message_t* msg, char *key)
{
    return _MAV_RETURN_char_array(msg, key, 20,  16);
}

/**
 * @brief Get field value from filter_angle message
 *
 * @return  
 */
static inline uint64_t mavlink_msg_filter_angle_get_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
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
    filter_angle->timestamp = mavlink_msg_filter_angle_get_timestamp(msg);
    filter_angle->value = mavlink_msg_filter_angle_get_value(msg);
    mavlink_msg_filter_angle_get_key(msg, filter_angle->key);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_Filter_Angle_LEN? msg->len : MAVLINK_MSG_ID_Filter_Angle_LEN;
        memset(filter_angle, 0, MAVLINK_MSG_ID_Filter_Angle_LEN);
    memcpy(filter_angle, _MAV_PAYLOAD(msg), len);
#endif
}
