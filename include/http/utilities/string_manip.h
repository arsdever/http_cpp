#pragma once

namespace http
{
	namespace utilities
	{
		template <typename T>
		concept container_concept = true;

		class string_manip
		{
		public:
			template <container_concept container_t, typename delim_t = std::string>
			static container_t split_string(std::string_view input, delim_t const& delim)
			{
				container_t result;
				while (1)
					{
						size_t pos = input.find_first_of(delim);
						if (pos == std::string_view::npos)
							break;

						result.push_back(std::string(input.substr(0, pos)));
						input = input.substr(pos + delim.size());
					}
				result.push_back(std::string(input));
				return result;
			}

			static std::string to_lower(std::string_view input)
			{
				std::string result;
				result.reserve(input.size());
				std::for_each(input.begin(), input.end(), [ &result ](const char& data) {
					result.push_back(std::tolower(data));
				});
				return result;
			}

			template <typename T = int>
			static T to_integral(std::string_view input)
			{
				T res = 0;
				for (auto ch : input)
					res = res * 10 + (ch - '0');
				return res;
			}
		};
	} // namespace utilities
} // namespace http