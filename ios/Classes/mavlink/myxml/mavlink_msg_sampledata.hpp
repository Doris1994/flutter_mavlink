// MESSAGE SAMPLEDATA support class

#pragma once

namespace mavlink {
namespace myxml {
namespace msg {

/**
 * @brief SAMPLEDATA message
 *
 * Sample output
 */
struct SAMPLEDATA : mavlink::Message {
    static constexpr msgid_t MSG_ID = 229;
    static constexpr size_t LENGTH = 20;
    static constexpr size_t MIN_LENGTH = 20;
    static constexpr uint8_t CRC_EXTRA = 101;
    static constexpr auto NAME = "SAMPLEDATA";


    int16_t curr; /*<  Sample curruet */
    int16_t volt; /*<  Sample voltage */
    int16_t temp; /*<  Sample temperature */
    int16_t alit; /*<  Sample altitude */
    int16_t pitch; /*<  Sample pitch */
    int16_t roll; /*<  Sample roll */
    int16_t yaw; /*<  Sample yaw */
    int16_t reserved1; /*<  Reserved 1 */
    int16_t reserved2; /*<  Reserved 2 */
    int16_t reserved3; /*<  Reserved 3 */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  curr: " << curr << std::endl;
        ss << "  volt: " << volt << std::endl;
        ss << "  temp: " << temp << std::endl;
        ss << "  alit: " << alit << std::endl;
        ss << "  pitch: " << pitch << std::endl;
        ss << "  roll: " << roll << std::endl;
        ss << "  yaw: " << yaw << std::endl;
        ss << "  reserved1: " << reserved1 << std::endl;
        ss << "  reserved2: " << reserved2 << std::endl;
        ss << "  reserved3: " << reserved3 << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << curr;                          // offset: 0
        map << volt;                          // offset: 2
        map << temp;                          // offset: 4
        map << alit;                          // offset: 6
        map << pitch;                         // offset: 8
        map << roll;                          // offset: 10
        map << yaw;                           // offset: 12
        map << reserved1;                     // offset: 14
        map << reserved2;                     // offset: 16
        map << reserved3;                     // offset: 18
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> curr;                          // offset: 0
        map >> volt;                          // offset: 2
        map >> temp;                          // offset: 4
        map >> alit;                          // offset: 6
        map >> pitch;                         // offset: 8
        map >> roll;                          // offset: 10
        map >> yaw;                           // offset: 12
        map >> reserved1;                     // offset: 14
        map >> reserved2;                     // offset: 16
        map >> reserved3;                     // offset: 18
    }
};

} // namespace msg
} // namespace myxml
} // namespace mavlink
