#pragma once

namespace http
{
	class request_header
	{
	public:
		using string_t = std::string;

		enum class known_header_enum
		{
			unknown,
			a_im,
			accept,
			accept_charset,
			accept_datetime,
			accept_encoding,
			accept_language,
			access_control_request_headers,
			access_control_request_method,
			authorization,
			cache_control,
			connection,
			content_encoding,
			content_length,
			content_md5,
			content_type,
			cookie,
			date,
			expect,
			forwarded,
			from,
			host,
			http2_settings,
			if_match,
			if_modified_since,
			if_none_match,
			if_range,
			if_unmodified_since,
			max_forwards,
			origin,
			pragma,
			prefer,
			proxy_authorization,
			range,
			referer,
			te,
			trailer,
			transfer_encoding,
			upgrade,
			user_agent,
			via,
			warning
		};

		static inline string_t header_key_to_string(known_header_enum const& h)
		{
			switch (h)
				{
				case known_header_enum::a_im: return "A-IM";
				case known_header_enum::accept: return "Accept";
				case known_header_enum::accept_charset: return "Accept-Charset";
				case known_header_enum::accept_datetime: return "Accept-Datetime";
				case known_header_enum::accept_encoding: return "Accept-Encoding";
				case known_header_enum::accept_language: return "Accept-Language";
				case known_header_enum::access_control_request_headers: return "Access-Control-Request-Headers";
				case known_header_enum::access_control_request_method: return "Access-Control-Request-Method";
				case known_header_enum::authorization: return "Authorization";
				case known_header_enum::cache_control: return "Cache-Control";
				case known_header_enum::connection: return "Connection";
				case known_header_enum::content_encoding: return "Content-Encoding";
				case known_header_enum::content_length: return "Content-Length";
				case known_header_enum::content_md5: return "Content-MD5";
				case known_header_enum::content_type: return "Content-Type";
				case known_header_enum::cookie: return "Cookie";
				case known_header_enum::date: return "Date";
				case known_header_enum::expect: return "Expect";
				case known_header_enum::forwarded: return "Forwarded";
				case known_header_enum::from: return "From";
				case known_header_enum::host: return "Host";
				case known_header_enum::http2_settings: return "HTTP2-Settings";
				case known_header_enum::if_match: return "If-Match";
				case known_header_enum::if_modified_since: return "If-Modified-Since";
				case known_header_enum::if_none_match: return "If-None-Match";
				case known_header_enum::if_range: return "If-Range";
				case known_header_enum::if_unmodified_since: return "If-Unmodified-Since";
				case known_header_enum::max_forwards: return "Max-Forwards";
				case known_header_enum::origin: return "Origin";
				case known_header_enum::pragma: return "Pragma";
				case known_header_enum::prefer: return "Prefer";
				case known_header_enum::proxy_authorization: return "Proxy-Authorization";
				case known_header_enum::range: return "Range";
				case known_header_enum::referer: return "Referer";
				case known_header_enum::te: return "TE";
				case known_header_enum::trailer: return "Trailer";
				case known_header_enum::transfer_encoding: return "Transfer-Encoding";
				case known_header_enum::upgrade: return "Upgrade";
				case known_header_enum::user_agent: return "User-Agent";
				case known_header_enum::via: return "Via";
				case known_header_enum::warning: return "Warning";
				default: return "Unknown";
				}
		}

		static inline known_header_enum header_key_from_string(string_t const& h)
		{
			if (h == "A-IM")
				{
					return known_header_enum::a_im;
				}
			else if (h == "Accept")
				{
					return known_header_enum::accept;
				}
			else if (h == "Accept-Charset")
				{
					return known_header_enum::accept_charset;
				}
			else if (h == "Accept-Datetime")
				{
					return known_header_enum::accept_datetime;
				}
			else if (h == "Accept-Encoding")
				{
					return known_header_enum::accept_encoding;
				}
			else if (h == "Accept-Language")
				{
					return known_header_enum::accept_language;
				}
			else if (h == "Access-Control-Request-Headers")
				{
					return known_header_enum::access_control_request_headers;
				}
			else if (h == "Access-Control-Request-Method")
				{
					return known_header_enum::access_control_request_method;
				}
			else if (h == "Authorization")
				{
					return known_header_enum::authorization;
				}
			else if (h == "Cache-Control")
				{
					return known_header_enum::cache_control;
				}
			else if (h == "Connection")
				{
					return known_header_enum::connection;
				}
			else if (h == "Content-Encoding")
				{
					return known_header_enum::content_encoding;
				}
			else if (h == "Content-Length")
				{
					return known_header_enum::content_length;
				}
			else if (h == "Content-MD5")
				{
					return known_header_enum::content_md5;
				}
			else if (h == "Content-Type")
				{
					return known_header_enum::content_type;
				}
			else if (h == "Cookie")
				{
					return known_header_enum::cookie;
				}
			else if (h == "Date")
				{
					return known_header_enum::date;
				}
			else if (h == "Expect")
				{
					return known_header_enum::expect;
				}
			else if (h == "Forwarded")
				{
					return known_header_enum::forwarded;
				}
			else if (h == "From")
				{
					return known_header_enum::from;
				}
			else if (h == "Host")
				{
					return known_header_enum::host;
				}
			else if (h == "HTTP2-Settings")
				{
					return known_header_enum::http2_settings;
				}
			else if (h == "If-Match")
				{
					return known_header_enum::if_match;
				}
			else if (h == "If-Modified-Since")
				{
					return known_header_enum::if_modified_since;
				}
			else if (h == "If-None-Match")
				{
					return known_header_enum::if_none_match;
				}
			else if (h == "If-Range")
				{
					return known_header_enum::if_range;
				}
			else if (h == "If-Unmodified-Since")
				{
					return known_header_enum::if_unmodified_since;
				}
			else if (h == "Max-Forwards")
				{
					return known_header_enum::max_forwards;
				}
			else if (h == "Origin")
				{
					return known_header_enum::origin;
				}
			else if (h == "Pragma")
				{
					return known_header_enum::pragma;
				}
			else if (h == "Prefer")
				{
					return known_header_enum::prefer;
				}
			else if (h == "Proxy-Authorization")
				{
					return known_header_enum::proxy_authorization;
				}
			else if (h == "Range")
				{
					return known_header_enum::range;
				}
			else if (h == "Referer")
				{
					return known_header_enum::referer;
				}
			else if (h == "TE")
				{
					return known_header_enum::te;
				}
			else if (h == "Trailer")
				{
					return known_header_enum::trailer;
				}
			else if (h == "Transfer-Encoding")
				{
					return known_header_enum::transfer_encoding;
				}
			else if (h == "Upgrade")
				{
					return known_header_enum::upgrade;
				}
			else if (h == "User-Agent")
				{
					return known_header_enum::user_agent;
				}
			else if (h == "Via")
				{
					return known_header_enum::via;
				}
			else if (h == "Warning")
				{
					return known_header_enum::warning;
				}
			else
				{
					return known_header_enum::unknown;
				}
		}

		request_header() : __key {}, __value {} { }
		request_header(request_header const& o) : __key { o.__key }, __value { o.__value } { }
		request_header(request_header&& o) : __key { o.__key }, __value { o.__value } { }
		request_header(known_header_enum const& key, string_t const& value) : __key { std::move(header_key_to_string(key)) }, __value { value } { }
		request_header(string_t const& key, string_t const& value) : __key { key }, __value { value } { }

		inline string_t key() const { return __key; }
		inline string_t value() const { return __value; }

		friend std::ostream& operator<<(std::ostream& stm, request_header const& header);

	private:
		string_t __key;
		string_t __value;
	};

	inline std::ostream& operator<<(std::ostream& stm, request_header const& header)
	{
		return stm << header.key() << ": " << header.value() << "\r\n";
	}

	inline std::ostream& operator<<(std::ostream& stm, request_header::known_header_enum const& header)
	{
		return stm << request_header::header_key_to_string(header);
	}
} // namespace http
