#pragma once

#include <http/utilities/string_manip.h>

namespace http
{
	class response_header
	{
	public:
#pragma region known_header_enum

		enum class known_header_enum
		{
			unknown,
			accept_ch,
			access_control_allow_origin,
			access_control_allow_credentials,
			access_control_expose_headers,
			access_control_max_age,
			access_control_allow_methods,
			access_control_allow_headers,
			accept_patch,
			accept_ranges,
			age,
			allow,
			alt_svc,
			chache_control,
			connection,
			content_disposition,
			content_encoding,
			content_language,
			content_length,
			content_location,
			content_md5,
			content_range,
			content_type,
			date,
			delta_base,
			etag,
			expires,
			im,
			last_modified,
			link,
			location,
			p3p,
			pragma,
			preference_applied,
			proxy_authenticate,
			public_key_pins,
			retry_after,
			server,
			set_cookie,
			strict_transport_security,
			trailer,
			transfer_encoding,
			tk,
			upgrade,
			vary,
			via,
			warning,
			www_authenticate,
			x_frame_options,
		};

		static std::string header_key_to_string(known_header_enum header)
		{
			switch (header)
				{
				case known_header_enum::accept_ch: return "Accept-CH";
				case known_header_enum::access_control_allow_origin: return "Accept-Patch";
				case known_header_enum::access_control_allow_credentials: return "Accept-Ranges";
				case known_header_enum::access_control_expose_headers: return "Access-Control-Allow-Credentials,";
				case known_header_enum::access_control_max_age: return "Access-Control-Allow-Headers";
				case known_header_enum::access_control_allow_methods: return "Access-Control-Allow-Methods,";
				case known_header_enum::access_control_allow_headers: return "Access-Control-Allow-Origin,";
				case known_header_enum::accept_patch: return "Access-Control-Expose-Headers,";
				case known_header_enum::accept_ranges: return "Access-Control-Max-Age,";
				case known_header_enum::age: return "Age";
				case known_header_enum::allow: return "Allow";
				case known_header_enum::alt_svc: return "Alt-Svc";
				case known_header_enum::chache_control: return "Cache-Control";
				case known_header_enum::connection: return "Connection";
				case known_header_enum::content_disposition: return "Content-Disposition";
				case known_header_enum::content_encoding: return "Content-Encoding";
				case known_header_enum::content_language: return "Content-Language";
				case known_header_enum::content_length: return "Content-Length";
				case known_header_enum::content_location: return "Content-Location";
				case known_header_enum::content_md5: return "Content-MD5";
				case known_header_enum::content_range: return "Content-Range";
				case known_header_enum::content_type: return "Content-Type";
				case known_header_enum::date: return "Date";
				case known_header_enum::delta_base: return "Delta-Base";
				case known_header_enum::etag: return "ETag";
				case known_header_enum::expires: return "Expires";
				case known_header_enum::im: return "IM";
				case known_header_enum::last_modified: return "Last-Modified";
				case known_header_enum::link: return "Link";
				case known_header_enum::location: return "Location";
				case known_header_enum::p3p: return "P3P";
				case known_header_enum::pragma: return "Pragma";
				case known_header_enum::preference_applied: return "Preference-Applied";
				case known_header_enum::proxy_authenticate: return "Proxy-Authenticate";
				case known_header_enum::public_key_pins: return "Public-Key-Pins";
				case known_header_enum::retry_after: return "Retry-After";
				case known_header_enum::server: return "Server";
				case known_header_enum::set_cookie: return "Set-Cookie";
				case known_header_enum::strict_transport_security: return "Strict-Transport-Security";
				case known_header_enum::trailer: return "Tk";
				case known_header_enum::transfer_encoding: return "Trailer";
				case known_header_enum::tk: return "Transfer-Encoding";
				case known_header_enum::upgrade: return "Upgrade";
				case known_header_enum::vary: return "Vary";
				case known_header_enum::via: return "Via";
				case known_header_enum::warning: return "Warning";
				case known_header_enum::www_authenticate: return "WWW-Authenticate";
				case known_header_enum::x_frame_options: return "X-Frame-Options";
				default: return "Unknown";
				}
		}

		static known_header_enum header_key_from_string(std::string const& v)
		{
			std::string val = v;
			// std::string val = utilities::string_manip::to_lower(v);
			if (val == "Accept-CH")
				return known_header_enum::accept_ch;
			else if (val == "Accept-Patch")
				return known_header_enum::access_control_allow_origin;
			else if (val == "Accept-Ranges")
				return known_header_enum::access_control_allow_credentials;
			else if (val == "Access-Control-Allow-Credentials,")
				return known_header_enum::access_control_expose_headers;
			else if (val == "Access-Control-Allow-Headers")
				return known_header_enum::access_control_max_age;
			else if (val == "Access-Control-Allow-Methods,")
				return known_header_enum::access_control_allow_methods;
			else if (val == "Access-Control-Allow-Origin,")
				return known_header_enum::access_control_allow_headers;
			else if (val == "Access-Control-Expose-Headers,")
				return known_header_enum::accept_patch;
			else if (val == "Access-Control-Max-Age,")
				return known_header_enum::accept_ranges;
			else if (val == "Age")
				return known_header_enum::age;
			else if (val == "Allow")
				return known_header_enum::allow;
			else if (val == "Alt-Svc")
				return known_header_enum::alt_svc;
			else if (val == "Cache-Control")
				return known_header_enum::chache_control;
			else if (val == "Connection")
				return known_header_enum::connection;
			else if (val == "Content-Disposition")
				return known_header_enum::content_disposition;
			else if (val == "Content-Encoding")
				return known_header_enum::content_encoding;
			else if (val == "Content-Language")
				return known_header_enum::content_language;
			else if (val == "Content-Length")
				return known_header_enum::content_length;
			else if (val == "Content-Location")
				return known_header_enum::content_location;
			else if (val == "Content-MD5")
				return known_header_enum::content_md5;
			else if (val == "Content-Range")
				return known_header_enum::content_range;
			else if (val == "Content-Type")
				return known_header_enum::content_type;
			else if (val == "Date")
				return known_header_enum::date;
			else if (val == "Delta-Base")
				return known_header_enum::delta_base;
			else if (val == "ETag")
				return known_header_enum::etag;
			else if (val == "Expires")
				return known_header_enum::expires;
			else if (val == "IM")
				return known_header_enum::im;
			else if (val == "Last-Modified")
				return known_header_enum::last_modified;
			else if (val == "Link")
				return known_header_enum::link;
			else if (val == "Location")
				return known_header_enum::location;
			else if (val == "P3P")
				return known_header_enum::p3p;
			else if (val == "Pragma")
				return known_header_enum::pragma;
			else if (val == "Preference-Applied")
				return known_header_enum::preference_applied;
			else if (val == "Proxy-Authenticate")
				return known_header_enum::proxy_authenticate;
			else if (val == "Public-Key-Pins")
				return known_header_enum::public_key_pins;
			else if (val == "Retry-After")
				return known_header_enum::retry_after;
			else if (val == "Server")
				return known_header_enum::server;
			else if (val == "Set-Cookie")
				return known_header_enum::set_cookie;
			else if (val == "Strict-Transport-Security")
				return known_header_enum::strict_transport_security;
			else if (val == "Tk")
				return known_header_enum::trailer;
			else if (val == "Trailer")
				return known_header_enum::transfer_encoding;
			else if (val == "Transfer-Encoding")
				return known_header_enum::tk;
			else if (val == "Upgrade")
				return known_header_enum::upgrade;
			else if (val == "Vary")
				return known_header_enum::vary;
			else if (val == "Via")
				return known_header_enum::via;
			else if (val == "Warning")
				return known_header_enum::warning;
			else if (val == "WWW-Authenticate")
				return known_header_enum::www_authenticate;
			else if (val == "X-Frame-Options")
				return known_header_enum::x_frame_options;
			else
				return known_header_enum::unknown;
		}

#pragma endregion

		response_header() : __key {}, __value {} { }
		response_header(response_header const& o) : __key { o.__key }, __value { o.__value } { }
		response_header(response_header&& o) : __key { o.__key }, __value { o.__value } { }
		response_header(std::string key, std::string value) : __key { key }, __value { value } { }

		inline std::string key() const { return __key; }
		inline std::string value() const { return __value; }

	private:
		std::string __key;
		std::string __value;
	};

	std::ostream& operator<<(std::ostream& stm, response_header::known_header_enum const& header)
	{
		return stm << response_header::header_key_to_string(header);
	}
} // namespace http