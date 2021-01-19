#include <ostream>
#include "schedule.h"
#include "exceptions.h"


using namespace mtm;
using std::cout;
using std::endl;

bool event_pointer_compare(BaseEvent* event1, BaseEvent* event2);
bool event_pointer_is_equal(BaseEvent* event1, BaseEvent* event2);

Schedule::Schedule(): event_list(){}
Schedule::~Schedule()
{
    for (BaseEvent* event: this->event_list)
    {
        delete event;
    }
    
}

//#TODO: check this worsk correctly
bool event_pointer_compare(BaseEvent* event1, BaseEvent* event2)
{
    return (*event1 < *event2) || (*event1 == *event2);
}

// bool event_pointer_is_equal(BaseEvent* event1, BaseEvent* event2)
// {
//     //TODO: check this gives the wnated result for equal events
//     return *event1 == *event2;
// }



void Schedule::addEvent(BaseEvent& event)
{
    BaseEvent* event_pointer = event.clone();
    this->event_list.push_back(event_pointer);
    this->event_list.sort(event_pointer_compare);
}

void Schedule::addEvents(const EventContainer& event_container)
{
    for(EventContainer::EventIterator iter_event = event_container.begin(); iter_event != event_container.end(); ++iter_event)
    {
        //#TODO: we can improve time complexity
        for(BaseEvent* event_p: this->event_list)
        {
            if(*iter_event == *event_p)
            {
                throw EventAlreadyExists();
            }
        }
    }
    for(EventContainer::EventIterator iter_event = event_container.begin(); iter_event != event_container.end(); ++iter_event)
    {
        this->addEvent(*iter_event);
    }
    

}

BaseEvent* Schedule::findEventByDateAndName(mtm::DateWrap date, std::string name) const
{
    for (BaseEvent* event_p: this->event_list)
    {
        if(event_p->getDate() == date && event_p->getName() == name)
        {
            return event_p;
        }
    }
    return NULL;
}

void Schedule::registerToEvent(DateWrap date, std::string name, int student)
{
    BaseEvent* event = this->findEventByDateAndName(date, name);
    if(!event)
    {
        throw EventDoesNotExist();
    }
    event->registerParticipant(student);
}

void Schedule::unregisterFromEvent(DateWrap date, std::string name, int student)
{
    BaseEvent* event = this->findEventByDateAndName(date, name);
    if(!event)
    {
        throw EventDoesNotExist();
    }
    event->unregisterParticipant(student);
}

void Schedule::printAllEvents() const
{
    for (BaseEvent* event: this->event_list)
    {
        event->printShort(cout) << endl;
    }
}

void Schedule::printMonthEvents(int month, int year)  const
{
    for (BaseEvent* event: this->event_list)
    {
        if(event->getDate().month() == month && event->getDate().year() == year)
        {
            event->printShort(cout) << endl;
        }
    }
}

void Schedule::printEventDetails(DateWrap date, std::string event_name) const
{
    BaseEvent* event = this->findEventByDateAndName(date, event_name);
    if(!event)
    {
        throw EventDoesNotExist();
    }
    event->printLong(cout) << endl;
}




