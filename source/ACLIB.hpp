#ifndef ACLIB_SHARED_MEMORY_ACLIB_HPP
#define ACLIB_SHARED_MEMORY_ACLIB_HPP

#include <cstdint>
#include <fstream>
#include <memory>
#include <string>
#include <xlocinfo.h>

class Log {
public:
    static std::fstream stream;
    static void log(std::string const& s) {
        Log::stream << s << std::endl;
    }
};

#define LOG(msg) Log::log(msg)

namespace ACLIB
{
    typedef std::uint32_t Uint32;
    typedef std::uint64_t Uint64;
    typedef std::int32_t  Sint32;
    typedef std::int64_t  Sint64;
    typedef wchar_t       WChar;

    typedef _ULonglong EventType;

    enum EVENT : EventType
    {
        PHYSICS  = 0x00000000,
        GEAR_CHANGED,
        GRAPHICS = 0x10000000,
        STATUS_CHANGED,
        SESSION_CHANGED,
        COMPLETED_LAPS_CHANGED,
        POSITION_CHANGED,
        IS_IN_PIT,
        STATICS  = 0x20000000,
    };

}  // namespace ACLIB

#endif  // ACLIB_SHARED_MEMORY_ACLIB_HPP
