#include "MyException.h"

namespace project
{
    Exception::Exception(const char *message)
        : message_(message) {}

    const char *Exception::what() const noexcept
    {
        return message_;
    }
}
