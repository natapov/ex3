#ifndef CLOSED_EVENT_H_
#define CLOSED_EVENT_H_

#include "base_event.h"
#include "list.h"
#include "exceptions.h"

namespace mtm
{
    class ClosedEvent;
}
class mtm::ClosedEvent : public mtm::BaseEvent
{
    List<int> invitees;
public:
    ClosedEvent(mtm::DateWrap date, std::string name);
    void registerParticipant(int participant) override;
    void addInvitee(int student);
    ClosedEvent* clone() const override;
};

#endif