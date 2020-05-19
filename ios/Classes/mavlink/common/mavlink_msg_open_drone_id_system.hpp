// MESSAGE OPEN_DRONE_ID_SYSTEM support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief OPEN_DRONE_ID_SYSTEM message
 *
 * Data for filling the OpenDroneID System message. The System Message contains general system information including the operator location and possible aircraft group information.
 */
struct OPEN_DRONE_ID_SYSTEM : mavlink::Message {
    static constexpr msgid_t MSG_ID = 12904;
    static constexpr size_t LENGTH = 21;
    static constexpr size_t MIN_LENGTH = 21;
    static constexpr uint8_t CRC_EXTRA = 238;
    static constexpr auto NAME = "OPEN_DRONE_ID_SYSTEM";


    uint8_t flags; /*<  Specifies the location source for the operator location. */
    int32_t operator_latitude; /*< [degE7] Latitude of the operator. If unknown: 0 (both Lat/Lon). */
    int32_t operator_longitude; /*< [degE7] Longitude of the operator. If unknown: 0 (both Lat/Lon). */
    uint16_t area_count; /*<  Number of aircraft in the area, group or formation (default 1). */
    uint16_t area_radius; /*< [m] Radius of the cylindrical area of the group or formation (default 0). */
    float area_ceiling; /*< [m] Area Operations Ceiling relative to WGS84. If unknown: -1000 m. */
    float area_floor; /*< [m] Area Operations Floor relative to WGS84. If unknown: -1000 m. */


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
        ss << "  flags: " << +flags << std::endl;
        ss << "  operator_latitude: " << operator_latitude << std::endl;
        ss << "  operator_longitude: " << operator_longitude << std::endl;
        ss << "  area_count: " << area_count << std::endl;
        ss << "  area_radius: " << area_radius << std::endl;
        ss << "  area_ceiling: " << area_ceiling << std::endl;
        ss << "  area_floor: " << area_floor << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << operator_latitude;             // offset: 0
        map << operator_longitude;            // offset: 4
        map << area_ceiling;                  // offset: 8
        map << area_floor;                    // offset: 12
        map << area_count;                    // offset: 16
        map << area_radius;                   // offset: 18
        map << flags;                         // offset: 20
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> operator_latitude;             // offset: 0
        map >> operator_longitude;            // offset: 4
        map >> area_ceiling;                  // offset: 8
        map >> area_floor;                    // offset: 12
        map >> area_count;                    // offset: 16
        map >> area_radius;                   // offset: 18
        map >> flags;                         // offset: 20
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
