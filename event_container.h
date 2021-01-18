#ifndef EVENT_CONTAINER_H_
#define EVENT_CONTAINER_H_

//#include "list.h"
#include "pointer_list.h"
#include "base_event.h"
#include "exceptions.h"

namespace mtm
{
    class EventContainer;
}

class mtm::EventContainer
{
private:
    PointerList events;

public:
    class EventIterator;
    EventContainer() ;
    virtual ~EventContainer(){};
    virtual void add(BaseEvent& event) =0;
    //virtual void add(BaseEvent& event);
    EventIterator begin();
    EventIterator end();
    
public:
    class EventIterator
    {
        PointerList::ListIterator listIter;
    public:
        EventIterator(PointerList::ListIterator listIter);
        
        EventIterator operator++();
        const BaseEvent& operator*() const;
        BaseEvent& operator*();
        bool operator==(const EventIterator& iterator);
        bool operator!=(const EventIterator& iterator);
    };
};


#endif