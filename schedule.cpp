#include <ostream>
#include "schedule.h"
#include "exceptions.h"


using namespace mtm;
using std::cout;
using std::endl;
using std::list;

bool event_pointer_compare(BaseEvent* event1, BaseEvent* event2);

Schedule::Schedule(): event_list(){}
Schedule::Schedule(const Schedule& schedule): event_list()
{
    for(BaseEvent* event: schedule.event_list)
    {
        this->event_list.push_back(event->clone());
    }
    this->event_list.sort(event_pointer_compare);
}
Schedule::~Schedule()
{
    this->freeEventPointers();
}


void Schedule::freeEventPointers()
{
    for (BaseEvent* event: this->event_list)
    {
        delete event;
    }
}

Schedule& Schedule::operator=(const Schedule& schedule)
{
    if(this == &schedule)
    {
        return *this;
    }
    list<BaseEvent*> event_list = list<BaseEvent*>();
    for(BaseEvent* event: schedule.event_list)
    {
        event_list.push_back(event->clone());
    }
    event_list.sort(event_pointer_compare);
    this->freeEventPointers();
    this->event_list = event_list;
    return *this;
}

//#TODO: check this worsk correctly
bool event_pointer_compare(BaseEvent* event1, BaseEvent* event2)
{
    return (*event1 < *event2) || (*event1 == *event2); //TODO: PASSES TESTS EVEN WITHOUT SECOND CONDITION, WHICH IS CORRECT?
}


void Schedule::addEvent(const BaseEvent& event)
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

BaseEvent* Schedule::findEventByDateAndName(const mtm::DateWrap& date, const std::string& name) const
{
    for (BaseEvent* event_p: this->event_list)
    {
        if(event_p->getDate() == date && event_p->getName() == name)
        {
            return event_p;
        }
    }
    return nullptr;
}

void Schedule::registerToEvent(const mtm::DateWrap& date, const std::string& name, int student)
{
    BaseEvent* event = this->findEventByDateAndName(date, name);
    if(!event)
    {
        throw EventDoesNotExist();
    }
    event->registerParticipant(student);
}

void Schedule::unregisterFromEvent(const mtm::DateWrap& date, const std::string& name, int student)
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

void Schedule::printEventDetails(const mtm::DateWrap& date, const std::string& event_name) const
{
    BaseEvent* event = this->findEventByDateAndName(date, event_name);
    if(!event)
    {
        throw EventDoesNotExist();
    }
    event->printLong(cout) << endl;
}
