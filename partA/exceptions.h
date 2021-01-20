#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

namespace mtm
{
    class Exception : std::exception{};
//datewrap:
    class NegativeDays : Exception{};

    class InvalidDate : Exception{};
//list
    class ValueNotInList : Exception{};
//base event
    class AlreadyInvited : Exception{};

    class AlreadyRegistered : Exception{};

    class NotRegistered: Exception{};

    class InvalidStudent : Exception{};

    class RegistrationBlocked : Exception{};

    class DateMismatch : Exception{};
//recurring event:
    class InvalidNumber : Exception{};

    class InvalidInterval : Exception{};

    class NotSupported : Exception{};
//schedule:
    class EventAlreadyExists: Exception{};

    class EventDoesNotExist: Exception{};
}

#endif