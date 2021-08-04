#pragma once

namespace http
{
	class i_logger
	{
	public:
		enum class log_level
		{
			fatal,
			error,
			warning,
			info,
			detail,
			debug
		};

		virtual ~i_logger() = default;

		virtual void log(log_level level, std::string const& message) = 0;
		virtual void fatal(std::string const& message)				   = 0;
		virtual void error(std::string const& message)				   = 0;
		virtual void warning(std::string const& message)			   = 0;
		virtual void info(std::string const& message)				   = 0;
		virtual void detail(std::string const& message)			   = 0;
		virtual void debug(std::string const& message)				   = 0;
	};
} // namespace http
