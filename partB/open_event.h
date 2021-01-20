#ifndef OPEN_EVENT_H_
#define OPEN_EVENT_H_

#include "base_event.h"

namespace mtm
{
    class OpenEvent;
}

class mtm::OpenEvent: public mtm::BaseEvent
{
public:
    OpenEvent(mtm::DateWrap date, std::string name);
    ~OpenEvent(){}//TO DO: does evrything still work if we remove this
    /** INHERETED 
    void registerParticipant(int participant); //causes compile error if included
    void unregisterParticipant(int participant);
    std::ostream& printShort(std::ostream& out);
    std::ostream& printLong(std::ostream& out);
    **/
    OpenEvent* clone() const override;
};

#endif