#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_

#include "base_event.h"

namespace mtm
{
    class OpenEvent;
}

class mtm::OpenEvent: mtm::BaseEvent
{
public:
    OpenEvent(std::string name, mtm::DateWrap date);
    void registerParticipant(int participant) override;
    void unregisterParticipant(int participant);
    std::ostream& printShort(std::ostream& out);
    std::ostream& printLong(std::ostream& out);
    OpenEvent* clone() const override;
};

#endif