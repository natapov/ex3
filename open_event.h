#include "base_event.h"
#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_

class OpenEvent : BaseEvent
{
public:
    BaseEvent(std::string name, mtm::DateWrap date);
    void registerParticipant(int participant);
    void unregisterParticipant(int participant);
    std::ostream& printShort(std::ostream& out);
    std::ostream& printLong(std::ostream& out);
    BaseEvent* clone() const;
}

#endif