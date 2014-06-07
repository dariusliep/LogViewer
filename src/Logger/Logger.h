#pragma once

#include <string>
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>

#define LOG(level) BOOST_LOG_TRIVIAL(level)

void InitLogging(const std::string & fileName)
{
    boost::log::add_file_log(
        boost::log::keywords::file_name = fileName,
        boost::log::keywords::rotation_size = 10 * 1024 * 1024,
        boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
        boost::log::keywords::format = "%TimeStamp% [%Severity%] %Message%",
        boost::log::keywords::auto_flush = true);

    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::trace);
}