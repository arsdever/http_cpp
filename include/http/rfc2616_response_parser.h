#pragma once

#include <http/response_parser_exception.h>
#include <http/server_response_builder.h>
#include <iterator>

constexpr auto LINEBREAK_SIZE = 2;
constexpr auto SP			  = ' ';
constexpr auto HT			  = '\t';
constexpr auto CR			  = '\r';
constexpr auto LF			  = '\n';

namespace http
{
	class rfc2616_response_parser
	{
	public:
		using builder_t = server_response_builder;

	public:
		rfc2616_response_parser() : __builder {}, __should_parse_body { false }, __body_length { 0 } { }

		template <typename iterator_t>
		void parse(iterator_t const& dbegin, iterator_t const& dend)
		{
			iterator_t tb = dbegin;
			iterator_t it = dbegin;

			while (*it != SP)
				{
					++it;
				}

			http_version ver = http_version_from_string(tb, it);

			++it;
			tb = it;
			while (*it != SP)
				{
					++it;
				}

			status_code sc = status_code_from_string(tb, it);

			++it;
			tb = it;

			while (*it != CR || *(it + 1) != LF)
				{
					++it;
				}

			std::string sm = std::string(tb, it);

			it += LINEBREAK_SIZE;
			tb = it;

			parse_headers(tb, dend);
			__builder.with_http_version(ver).with_status_code(sc).with_status_message(sm);

			if (__should_parse_body)
				{
					std::string body = std::string(tb, dend);
					if (body.size() == __body_length)
						{
							__builder.with_body(body);
						}
				}
		}

		builder_t builder() const { return __builder; }

	private:
		template <typename iterator_t>
		void parse_headers(iterator_t& tb, iterator_t const& dend)
		{
			iterator_t			 it = tb;
			builder_t::headers_t headers;
			std::string			 hk;
			std::string			 hv;
			bool				 fin		 = false;
			auto				 push_header = [ & ](response_header&& hdr) {
				if (hdr.key() == response_header::known_header_enum::content_length ||
					hdr.key() == response_header::known_header_enum::transfer_encoding)
					{
						__should_parse_body = true;
					}
				if (hdr.key() == response_header::known_header_enum::content_length)
					{
						__body_length = std::stoi(hdr.value());
					}
				__builder.with_header(hdr);
			};

			hk.reserve(255);
			hv.reserve(1024);

			while (it != dend)
				{
					if (*it == SP || *it == HT)
						{
							fin = true;
							if (hk.empty())
								{
									throw response_parser_exception("Header name is missing.");
								}

							while (*it == SP || *it == HT)
								{
									++it;
								}

							hv.push_back(' ');
							while (*it != CR || *(it + 1) != LF)
								{
									hv.push_back(*it++);
								}

							it += LINEBREAK_SIZE;
							continue;
						}

					if (fin)
						{
							response_header hdr { hk, hv };
							push_header(std::move(hdr));
							hk	= "";
							hv	= "";
							fin = false;
						}

					if (*it == CR && *(it + 1) == LF)
						{
							it += LINEBREAK_SIZE;
							tb = it;
							return;
						}

					while (*it != ':')
						{
							hk.push_back(*it++);
						}

					++it;
					while (*it == SP || *it == HT)
						{
							++it;
						}

					while (*it != CR || *(it + 1) != LF)
						{
							hv.push_back(*it);
							++it;
						}

					it += LINEBREAK_SIZE;
					fin = true;
				}

			tb = it;
			response_header hdr { hk, hv };
			push_header(std::move(hdr));
		}

		template <typename iterator_t>
		http_version http_version_from_string(iterator_t const& b, iterator_t const& e)
		{
			static const std::string pattern = "http/";

			iterator_t					i = b;
			std::string::const_iterator j = pattern.begin();

			for (; i != e && j != pattern.end(); ++i, ++j)
				{
					if (tolower(*i) != *j)
						{
							throw response_parser_exception("Invalid HTTP version format.");
						}
				}

			int num = *i - '0';
			++++i;
			num = 10 * num + *i - '0';
			return static_cast<http_version>(num);
		}

		template <typename iterator_t>
		status_code status_code_from_string(iterator_t const& b, iterator_t const& e)
		{
			int	 num = 0;
			auto it	 = b;
			while (it != e)
				{
					if (!isdigit(*it))
						{
							throw response_parser_exception("Invalid HTTP code.");
						}

					num *= 10;
					num += *(it++) - '0';
				}

			return static_cast<status_code>(num);
		}

	private:
		builder_t __builder;
		bool	  __should_parse_body;
		size_t	  __body_length;
	};
} // namespace http