#pragma once

namespace http
{
	enum class request_method
	{
		RM_UNKNOWN,
		RM_OPTIONS,
		RM_GET,
		RM_HEAD,
		RM_POST,
		RM_PUT,
		RM_DELETE,
		RM_TRACE,
		RM_CONNECT
	};

	inline std::string request_method_to_string(request_method method)
	{
		switch (method)
			{
			case request_method::RM_OPTIONS: return "OPTIONS";
			case request_method::RM_GET: return "GET";
			case request_method::RM_HEAD: return "HEAD";
			case request_method::RM_POST: return "POST";
			case request_method::RM_PUT: return "PUT";
			case request_method::RM_DELETE: return "DELETE";
			case request_method::RM_TRACE: return "TRACE";
			case request_method::RM_CONNECT: return "CONNECT";
			default: return "UNKNOWN";
			}
	}

	inline request_method request_method_from_string(std::string const& req)
	{
		if (req == "OPTIONS")
			{
				return request_method::RM_OPTIONS;
			}
		else if (req == "GET")
			{
				return request_method::RM_GET;
			}
		else if (req == "HEAD")
			{
				return request_method::RM_HEAD;
			}
		else if (req == "POST")
			{
				return request_method::RM_POST;
			}
		else if (req == "PUT")
			{
				return request_method::RM_PUT;
			}
		else if (req == "DELETE")
			{
				return request_method::RM_DELETE;
			}
		else if (req == "TRACE")
			{
				return request_method::RM_TRACE;
			}
		else if (req == "CONNECT")
			{
				return request_method::RM_CONNECT;
			}

		return request_method::RM_UNKNOWN;
	}

	inline std::ostream& operator<<(std::ostream& s, request_method const& m) { return s << request_method_to_string(m); }

	inline bool operator==(request_method const& m, std::string const& s) { return m == request_method_from_string(s); }
} // namespace http
