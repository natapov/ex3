#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

namespace mtm
{
    class Exception : std::exception{};

    class NegativeDays : Exception{};

    class ValueNotInList : Exception{};
}

//date wrap

#endif