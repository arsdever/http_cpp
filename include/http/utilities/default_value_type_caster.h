#pragma once

#include <http/utilities/value_caster_concept.h>

template <typename S, typename T>
struct default_value_caster
{
	static constexpr bool exists = false;
};

template <>
struct default_value_caster<std::string, std::string>
{
	static constexpr bool exists = true;
	static constexpr std::string cast(std::string const& str) { return str; }
};

template <>
struct default_value_caster<std::string, bool>
{
	static constexpr bool exists = true;
	static constexpr bool cast(std::string const& str) { return str == "true"; }
};

template <>
struct default_value_caster<std::string, int>
{
	static constexpr bool exists = true;
	static int cast(std::string const& str) { return std::stoi(str); }
};
