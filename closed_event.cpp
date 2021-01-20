#include "closed_event.h"

using mtm::AlreadyInvited;
using mtm::ClosedEvent;

ClosedEvent::ClosedEvent(mtm::DateWrap date, std::string name): BaseEvent(date, name), invitees(){}

void ClosedEvent::addInvitee(int student)
{
    if (student > this->MAX_STUDENT || student < this->MIN_STUDENT)
    {
        throw InvalidStudent();
    }
    if(invitees.contains(student))
    {
        throw AlreadyInvited();
    }
    invitees.add(student);
}

void ClosedEvent::registerParticipant(int participant) 
{
    if (participant > this->MAX_STUDENT || participant < this->MIN_STUDENT)
    {
        throw InvalidStudent();
    }
    if(invitees.contains(participant))
    {
        BaseEvent::registerParticipant(participant);
    }
    else
    {
        throw RegistrationBlocked();
    }
}
ClosedEvent* ClosedEvent::clone() const
{
    ClosedEvent* cloned_event = new ClosedEvent(this->date, this->name);
    cloned_event->participants = this->participants;
    cloned_event->invitees = this->invitees;
    return cloned_event;
}