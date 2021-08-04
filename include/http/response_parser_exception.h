#pragma once

#include <exception>

namespace http
{
	class response_parser_exception : public std::exception
	{
	public:
		response_parser_exception(std::string const& msg) : std::exception(msg.c_str()) { }
	};
} // namespace http