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
    virtual void add(const BaseEvent& event) =0;
    EventIterator begin() const;
    EventIterator end() const;
    class EventIterator
    {
        PointerList::ListIterator listIter;
    public:
        EventIterator(PointerList::ListIterator listIter);
        
        EventIterator operator++();
        const BaseEvent& operator*() const;
        BaseEvent& operator*();
        bool operator==(const EventIterator& iterator) const;
        bool operator!=(const EventIterator& iterator) const;
    };
};

#endif