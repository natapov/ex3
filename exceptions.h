#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

namespace mtm
{
    class Exception : std::exception{};

    class NegativeDays : Exception{};

    class ValueNotInList : Exception{};

    class AlreadyInvited : Exception{};

    class AlreadyRegistered : Exception{};

    class InvalidStudent : Exception{};

    class RegistrationBlocked : Exception{};
}

//date wrap

#endif