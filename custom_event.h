#ifndef CUSTOM_EVENT_H_
#define CUSTOM_EVENT_H_

#include "base_event.h"

namespace mtm
{
    template <class CanRegister>
    class CustomEvent;
}

template <typename CanRegister>
class mtm::CustomEvent: public mtm::BaseEvent
{
private:
    CanRegister can_register;
public:
    CustomEvent(mtm::DateWrap date,std::string name, CanRegister can_register);
    ~CustomEvent(){}
    void registerParticipant(int participant) override;
    /**
    void unregisterParticipant(int participant);
    std::ostream& printShort(std::ostream& out);
    std::ostream& printLong(std::ostream& out);
    **/
    CustomEvent* clone() const override;


};

namespace mtm 
{
    template <typename CanRegister>
    CustomEvent<CanRegister>::CustomEvent(mtm::DateWrap date, std::string name, CanRegister function): BaseEvent(date, name), can_register(function) {}

    template <typename CanRegister>
    void CustomEvent<CanRegister>::registerParticipant(int participant) 
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

    template <typename CanRegister>
    CustomEvent<CanRegister>* CustomEvent<CanRegister>::clone() const
    {
        CustomEvent* cloned_event = new CustomEvent(this->date,this->name, this->can_register);
        cloned_event->participants = this->participants;
        return cloned_event;
    }
}
#endif