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

	inline std::ostream& operator<<(std::ostream& stm, http_version const& val)
	{
		switch (val)
			{
			case http_version::unknown: return stm << "unknown";
			case http_version::http_09: return stm << "HTTP/0.9";
			case http_version::http_10: return stm << "HTTP/1.0";
			case http_version::http_11: return stm << "HTTP/1.1";
			case http_version::http_20: return stm << "HTTP/2.0";
			default: return stm;
			}
	}
}