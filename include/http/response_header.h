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

		static constexpr std::string_view header_key_to_string(known_header_enum header)
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

		static known_header_enum header_key_from_string(std::string_view v)
		{
			if (v == "Accept-CH")
				return known_header_enum::accept_ch;
			else if (v == "Accept-Patch")
				return known_header_enum::access_control_allow_origin;
			else if (v == "Accept-Ranges")
				return known_header_enum::access_control_allow_credentials;
			else if (v == "Access-Control-Allow-Credentials,")
				return known_header_enum::access_control_expose_headers;
			else if (v == "Access-Control-Allow-Headers")
				return known_header_enum::access_control_max_age;
			else if (v == "Access-Control-Allow-Methods,")
				return known_header_enum::access_control_allow_methods;
			else if (v == "Access-Control-Allow-Origin,")
				return known_header_enum::access_control_allow_headers;
			else if (v == "Access-Control-Expose-Headers,")
				return known_header_enum::accept_patch;
			else if (v == "Access-Control-Max-Age,")
				return known_header_enum::accept_ranges;
			else if (v == "Age")
				return known_header_enum::age;
			else if (v == "Allow")
				return known_header_enum::allow;
			else if (v == "Alt-Svc")
				return known_header_enum::alt_svc;
			else if (v == "Cache-Control")
				return known_header_enum::chache_control;
			else if (v == "Connection")
				return known_header_enum::connection;
			else if (v == "Content-Disposition")
				return known_header_enum::content_disposition;
			else if (v == "Content-Encoding")
				return known_header_enum::content_encoding;
			else if (v == "Content-Language")
				return known_header_enum::content_language;
			else if (v == "Content-Length")
				return known_header_enum::content_length;
			else if (v == "Content-Location")
				return known_header_enum::content_location;
			else if (v == "Content-MD5")
				return known_header_enum::content_md5;
			else if (v == "Content-Range")
				return known_header_enum::content_range;
			else if (v == "Content-Type")
				return known_header_enum::content_type;
			else if (v == "Date")
				return known_header_enum::date;
			else if (v == "Delta-Base")
				return known_header_enum::delta_base;
			else if (v == "ETag")
				return known_header_enum::etag;
			else if (v == "Expires")
				return known_header_enum::expires;
			else if (v == "IM")
				return known_header_enum::im;
			else if (v == "Last-Modified")
				return known_header_enum::last_modified;
			else if (v == "Link")
				return known_header_enum::link;
			else if (v == "Location")
				return known_header_enum::location;
			else if (v == "P3P")
				return known_header_enum::p3p;
			else if (v == "Pragma")
				return known_header_enum::pragma;
			else if (v == "Preference-Applied")
				return known_header_enum::preference_applied;
			else if (v == "Proxy-Authenticate")
				return known_header_enum::proxy_authenticate;
			else if (v == "Public-Key-Pins")
				return known_header_enum::public_key_pins;
			else if (v == "Retry-After")
				return known_header_enum::retry_after;
			else if (v == "Server")
				return known_header_enum::server;
			else if (v == "Set-Cookie")
				return known_header_enum::set_cookie;
			else if (v == "Strict-Transport-Security")
				return known_header_enum::strict_transport_security;
			else if (v == "Tk")
				return known_header_enum::trailer;
			else if (v == "Trailer")
				return known_header_enum::transfer_encoding;
			else if (v == "Transfer-Encoding")
				return known_header_enum::tk;
			else if (v == "Upgrade")
				return known_header_enum::upgrade;
			else if (v == "Vary")
				return known_header_enum::vary;
			else if (v == "Via")
				return known_header_enum::via;
			else if (v == "Warning")
				return known_header_enum::warning;
			else if (v == "WWW-Authenticate")
				return known_header_enum::www_authenticate;
			else if (v == "X-Frame-Options")
				return known_header_enum::x_frame_options;
			else
				return known_header_enum::unknown;
		}

#pragma endregion

		response_header()						  = default;
		response_header(response_header const& o) = default;
		response_header(response_header&& o)	  = default;
		response_header(std::string_view key, std::string_view value) : __key { key }, __value { value } { }

		std::string_view key() const { return __key; }
		std::string_view value() const { return __value; }

	private:
		std::string __key;
		std::string __value;
	};

	std::ostream& operator<<(std::ostream& stm, response_header::known_header_enum const& header)
	{
		return stm << response_header::header_key_to_string(header);
	}
} // namespace http