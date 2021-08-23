#pragma once

#include <modm/board.hpp>
#include <lely/can/msg.h>

static bool convert_can_msg(const modm::can::Message& in, can_msg& out){
	bool result = false;
	out.id = in.getIdentifier();
	out.len = in.getLength();
	std::memcpy(&out.data[0], &in.data[0], out.len);
	out.flags = (in.isExtended() ? 1u << 0: 0u) | 
		(in.isRemoteTransmitRequest() ? 1u << 1: 0u);
	result = true;
	return result;
}

static bool convert_can_msg(const can_msg& in, modm::can::Message& out){
	bool result = false;
	out.setIdentifier(in.id);
	out.setLength(in.len);
	std::memcpy(&out.data[0], &in.data[0], in.len);
	out.setExtended(in.flags & (1u << 0));
	out.setRemoteTransmitRequest(in.flags & (1u << 1));
	result = true;
	return result;
}