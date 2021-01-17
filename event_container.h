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
    List<BaseEvent> events;  
    class EventIterator
    {
        List<BaseEvent>::ListIterator listIter;
        public:
        EventIterator(ListIterator listIter): listIter(listIter){}
        
        EventIterator operator++()
        {
            this->listIter++;
        }
        EventIterator begin()
        {
           EventIterator(listIter.begin())
        }
        EventIterator end()
        {
           EventIterator(listIter.end())
        }
    }

    

public:
    EventContainer();
    void add(BaseEvent& event);
}
mtm{
void EventContainer::add(BaseEvent& event)
{
    events.add(event);
}
void EventContainer::EventContainer(): List<EventContainer>{}

}
#endif