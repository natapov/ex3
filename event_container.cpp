#include "event_container.h"

using mtm::EventContainer;
using mtm::BaseEvent;


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



EventContainer::EventIterator::EventIterator(mtm::List<BaseEvent&>::ListIterator listIter): listIter(listIter){}



EventContainer::EventIterator EventContainer::EventIterator::operator++()
{
    return ++(this->listIter);
}
const BaseEvent& EventContainer::EventIterator::operator*() const{
    return *(this->listIter);
}
BaseEvent& EventContainer::EventIterator::operator*() {
    return *(this->listIter);
}
bool EventContainer::EventIterator::operator==(const EventContainer::EventIterator& iterator)
{
    return this->listIter == iterator.listIter;
}

bool EventContainer::EventIterator::operator!=(const EventContainer::EventIterator& iterator)
{
    return this->listIter != iterator.listIter;
}