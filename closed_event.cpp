#include "closed_event.h"

using mtm::AlreadyInvited;
using mtm::ClosedEvent;

ClosedEvent::ClosedEvent(std::string name, mtm::DateWrap date): BaseEvent(name, date), invitees(){}

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
    ClosedEvent* cloned_event = new ClosedEvent(this->name, this->date);
    cloned_event->participants = this->participants;
    cloned_event->invitees = this->invitees;
    return cloned_event;
}