#ifndef CUSTOM_EVENT_H_
#define CUSTOM_EVENT_H_

#include "base_event.h"

namespace mtm
{
    class CustomEvent;
}

class CanRegister
{
public:
    bool operator()(int id) const
    {
        return true;
    }
};

class mtm::CustomEvent: public mtm::BaseEvent
{
private:
    CanRegister can_register;
public:
    CustomEvent(std::string name, mtm::DateWrap date, CanRegister can_register);
    ~CustomEvent(){}
    void registerParticipant(int participant) override;
    /**
    void unregisterParticipant(int participant);
    std::ostream& printShort(std::ostream& out);
    std::ostream& printLong(std::ostream& out);
    **/
    CustomEvent* clone() const override;
    
};

#endif