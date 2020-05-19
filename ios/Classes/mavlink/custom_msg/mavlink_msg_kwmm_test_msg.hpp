// MESSAGE KWMM_TEST_MSG support class

#pragma once

namespace mavlink {
namespace custom_msg {
namespace msg {

/**
 * @brief KWMM_TEST_MSG message
 *
 * Test Custom information
 */
struct KWMM_TEST_MSG : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50001;
    static constexpr size_t LENGTH = 2;
    static constexpr size_t MIN_LENGTH = 2;
    static constexpr uint8_t CRC_EXTRA = 32;
    static constexpr auto NAME = "KWMM_TEST_MSG";


    uint16_t value; /*<  current value */


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
        ss << "  value: " << value << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << value;                         // offset: 0
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> value;                         // offset: 0
    }
};

} // namespace msg
} // namespace custom_msg
} // namespace mavlink
