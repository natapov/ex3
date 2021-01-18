#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

namespace mtm
{
    class Exception : std::exception{};

    class NegativeDays : Exception{};

    class InvalidDate : Exception{};

    class ValueNotInList : Exception{};

    class AlreadyInvited : Exception{};

    class AlreadyRegistered : Exception{};

    class InvalidStudent : Exception{};

    class RegistrationBlocked : Exception{};

    class DateMismatch : Exception{};
}

#endif