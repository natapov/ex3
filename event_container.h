#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_

#include "list.h"
#include "base_event.h"

namespace mtm
{
    class EventContainer;
}

class mtm::EventContainer
{
private:
    List<BaseEvent&> events;

public:
    class EventIterator;
    EventContainer();
    void add(BaseEvent& event);
    EventIterator begin();
    EventIterator end();
    
public:
    class EventIterator
    {
        List<BaseEvent&>::ListIterator listIter;
        public:
        EventIterator(List<BaseEvent&>::ListIterator listIter): listIter(listIter){}
        
        EventIterator operator++()
        {
            return ++(this->listIter);
        }
        const BaseEvent& operator*() const{
            return *(this->listIter);
        }

        bool operator==(const EventIterator& iterator)
        {
            return this->listIter == iterator.listIter;
        }

        bool operator!=(const EventIterator& iterator)
        {
            return this->listIter != iterator.listIter;
        }
    };
};


namespace mtm{

EventContainer::EventContainer(): events(){}

void EventContainer::add(BaseEvent& event)
{
    this->events.add(event);
}

EventContainer::EventIterator EventContainer::begin()
{
    return EventIterator(this->events.begin());
}


EventContainer::EventIterator EventContainer::end()
{
    return EventIterator(this->events.end());
}

}
#endif