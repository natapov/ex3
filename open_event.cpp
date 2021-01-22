#include "open_event.h"

using mtm::OpenEvent;

OpenEvent::OpenEvent(const mtm::DateWrap& date, const std::string& name): BaseEvent(date,name){}

OpenEvent* OpenEvent::clone() const
{
    OpenEvent* cloned_event = new OpenEvent(this->date, this->name);
    cloned_event->participants = this->participants;
    return cloned_event;
}
