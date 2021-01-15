#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_

#include "base_event.h"

namespace mtm
{
    class CustomEvent;
}

class func
{
public:
    bool operator()(int id) const
    {
        return true;
    }
};

typedef func CanRegister; 
class mtm::CustomEvent: mtm::BaseEvent
{
private:
    CanRegister can_register;
public:
    CustomEvent(std::string name, mtm::DateWrap date, CanRegister can_register);
    void registerParticipant(int participant) override;
    void unregisterParticipant(int participant);
    std::ostream& printShort(std::ostream& out);
    std::ostream& printLong(std::ostream& out);
    CustomEvent* clone() const;
};

#endif