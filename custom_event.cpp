#include "custom_event.h"

using mtm::AlreadyInvited;
using mtm::CustomEvent;
using mtm::RegistrationBlocked;

CustomEvent::CustomEvent(std::string name, mtm::DateWrap date, CanRegister function): BaseEvent(name, date), can_register(function) {}

void CustomEvent::registerParticipant(int participant) 
{
    if(this->can_register(participant))
    {
        BaseEvent::registerParticipant(participant);
    }
    else
    {
        throw RegistrationBlocked();
    }

}

CustomEvent* CustomEvent::clone() const
{
    CustomEvent* cloned_event = new CustomEvent(this->name, this->date, this->can_register);
    cloned_event->participants = this->participants;
    return cloned_event;
}