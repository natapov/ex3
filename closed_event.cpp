#include "closed_event.h"

using mtm::AlreadyInvited;
using mtm::ClosedEvent;

ClosedEvent::ClosedEvent(mtm::DateWrap date, std::string name): BaseEvent(date, name), invitees(){}

void ClosedEvent::addInvitee(int student)
{
    if(invitees.contains(student))
    {
        throw AlreadyInvited();
    }
    invitees.add(student);
}

void ClosedEvent::registerParticipant(int participant) 
{
    if(invitees.contains(participant))
    {
        BaseEvent::registerParticipant(participant);
    }
}
ClosedEvent* ClosedEvent::clone() const
{
    ClosedEvent* cloned_event = new ClosedEvent(this->date, this->name);
    cloned_event->participants = this->participants;
    cloned_event->invitees = this->invitees;
    return cloned_event;
}