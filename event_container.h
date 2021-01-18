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
    EventContainer() ;
    virtual ~EventContainer(){};
    //virtual void add(BaseEvent& event) =0;
    virtual void add(BaseEvent& event);
    EventIterator begin();
    EventIterator end();
    
public:
    class EventIterator
    {
        List<BaseEvent&>::ListIterator listIter;
    public:
        EventIterator(List<BaseEvent&>::ListIterator listIter);
        
        EventIterator operator++();
        const BaseEvent& operator*() const;
        BaseEvent& operator*();
        bool operator==(const EventIterator& iterator);
        bool operator!=(const EventIterator& iterator);
    };
};


// namespace mtm{

// EventContainer::EventContainer(): events(){}

// void EventContainer::add(BaseEvent& event)
// {
//     this->events.add(event);
// }

// EventContainer::EventIterator EventContainer::begin()
// {
//     return EventIterator(this->events.begin());
// }


// EventContainer::EventIterator EventContainer::end()
// {
//     return EventIterator(this->events.end());
// }

// }
#endif