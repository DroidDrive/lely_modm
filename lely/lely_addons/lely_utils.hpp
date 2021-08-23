#pragma once

#include <lely/can/msg.h>
#include <modm/board.hpp>

static bool convert_can_msg(const modm::can::Message& in, can_msg& out)
{
    bool result = false;
    out.id = in.getIdentifier();
    out.len = in.getLength();
    std::memcpy(&out.data[0], &in.data[0], out.len);
    out.flags = (in.isExtended() ? 1u << 0 : 0u)
        | (in.isRemoteTransmitRequest() ? 1u << 1 : 0u);
    result = true;
    return result;
}

static bool convert_can_msg(const can_msg& in, modm::can::Message& out)
{
    bool result = false;
    out.setIdentifier(in.id);
    out.setLength(in.len);
    std::memcpy(&out.data[0], &in.data[0], in.len);
    out.setExtended(in.flags & (1u << 0));
    out.setRemoteTransmitRequest(in.flags & (1u << 1));
    result = true;
    return result;
}

static void candump(const can_msg& msg_, uint8_t id = 0)
{
    std::stringstream ss;
    ss << std::hex << static_cast<int>(msg_.id);
    MODM_LOG_INFO << "<- can" << id << " ";
    std::string tmp = ss.str() + "#";
    unsigned int id_length = log(msg_.id) / log(16) + 1;
    for (unsigned i = id_length; i < 3; ++i) {
        MODM_LOG_INFO << " ";
    }
    for (unsigned i = tmp.length() - id_length - 1; i < tmp.length(); ++i) {
        MODM_LOG_INFO << tmp[i];
    }
    for (unsigned int i = 0; i < msg_.len; ++i) {
        MODM_LOG_INFO << modm::hex << msg_.data[i] << modm::ascii << " ";
    }
    MODM_LOG_INFO << modm::endl;
}
