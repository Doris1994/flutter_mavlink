// MESSAGE COMPONENT_INFORMATION support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief COMPONENT_INFORMATION message
 *
 * Information about a component. For camera components instead use CAMERA_INFORMATION, and for autopilots use AUTOPILOT_VERSION. Components including GCSes should consider supporting requests of this message via MAV_CMD_REQUEST_MESSAGE.
 */
struct COMPONENT_INFORMATION : mavlink::Message {
    static constexpr msgid_t MSG_ID = 395;
    static constexpr size_t LENGTH = 222;
    static constexpr size_t MIN_LENGTH = 222;
    static constexpr uint8_t CRC_EXTRA = 231;
    static constexpr auto NAME = "COMPONENT_INFORMATION";


    uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    std::array<uint8_t, 32> vendor_name; /*<  Name of the component vendor */
    std::array<uint8_t, 32> model_name; /*<  Name of the component model */
    uint32_t firmware_version; /*<  Version of the component firmware (v << 24 & 0xff = Dev, v << 16 & 0xff = Patch, v << 8 & 0xff = Minor, v & 0xff = Major) */
    uint32_t hardware_version; /*<  Version of the component hardware (v << 24 & 0xff = Dev, v << 16 & 0xff = Patch, v << 8 & 0xff = Minor, v & 0xff = Major) */
    uint32_t capability_flags; /*<  Bitmap of component capability flags. */
    uint16_t component_definition_version; /*<  Component definition version (iteration) */
    std::array<char, 140> component_definition_uri; /*<  Component definition URI (if any, otherwise only basic functions will be available). The XML format is not yet specified and work in progress.  */


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
        ss << "  time_boot_ms: " << time_boot_ms << std::endl;
        ss << "  vendor_name: [" << to_string(vendor_name) << "]" << std::endl;
        ss << "  model_name: [" << to_string(model_name) << "]" << std::endl;
        ss << "  firmware_version: " << firmware_version << std::endl;
        ss << "  hardware_version: " << hardware_version << std::endl;
        ss << "  capability_flags: " << capability_flags << std::endl;
        ss << "  component_definition_version: " << component_definition_version << std::endl;
        ss << "  component_definition_uri: \"" << to_string(component_definition_uri) << "\"" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << firmware_version;              // offset: 4
        map << hardware_version;              // offset: 8
        map << capability_flags;              // offset: 12
        map << component_definition_version;  // offset: 16
        map << vendor_name;                   // offset: 18
        map << model_name;                    // offset: 50
        map << component_definition_uri;      // offset: 82
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> firmware_version;              // offset: 4
        map >> hardware_version;              // offset: 8
        map >> capability_flags;              // offset: 12
        map >> component_definition_version;  // offset: 16
        map >> vendor_name;                   // offset: 18
        map >> model_name;                    // offset: 50
        map >> component_definition_uri;      // offset: 82
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
