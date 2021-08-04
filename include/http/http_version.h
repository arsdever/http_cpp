#pragma once

namespace http
{
	enum class http_version
	{
		unknown = 0,
		http_09 = 9,
		http_10 = 10,
		http_11 = 11,
		http_20 = 20,
	};

	std::ostream& operator<<(std::ostream& stm, http_version const& val)
	{
		switch (val)
			{
			case http_version::unknown: return stm << "unknown";
			case http_version::http_09: return stm << "http_09";
			case http_version::http_10: return stm << "http_10";
			case http_version::http_11: return stm << "http_11";
			case http_version::http_20: return stm << "http_20";
			default: return stm;
			}
	}
}