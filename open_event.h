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
    OpenEvent(const mtm::DateWrap& date, const std::string& name);
    OpenEvent* clone() const override;
};

#endif