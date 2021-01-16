#ifndef CLOSED_EVENT_H_
#define CLOSED_EVENT_H_

#include "base_event.h"
#include "list.h"
#include "exceptions.h"

namespace mtm
{
    class ClosedEvent;
}
class mtm::ClosedEvent : public BaseEvent
{
    List invitees;
public:
    ClosedEvent(std::string name, mtm::DateWrap date);
    void registerParticipant(int participant);
    void unregisterParticipant(int participant);
    void addInvitee(int student);
    std::ostream& printShort(std::ostream& out);
    std::ostream& printLong(std::ostream& out);
    ClosedEvent* clone() const override;
};

#endif