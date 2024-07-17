#pragma once

#include <iostream>
#include <exception>

namespace project
{
    class Exception : public std::exception
    {
    public:
        explicit Exception(const char *message);
        virtual const char *what() const noexcept override;

    private:
        const char *message_;
    };
}
