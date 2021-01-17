#include "open_event.h"

using mtm::OpenEvent;

OpenEvent::OpenEvent(std::string name, mtm::DateWrap date): BaseEvent(name,date){}

OpenEvent* OpenEvent::clone() const
{
    OpenEvent* cloned_event = new OpenEvent(this->name, this->date);
    cloned_event->participants = this->participants;
    return cloned_event;
}
