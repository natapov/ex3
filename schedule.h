#ifndef SCEHDULE_H
#define SCEHDULE_H

#include <stdbool.h>
#include <string>
#include <list>
#include <iostream>
#include "base_event.h"
#include "date_wrap.h"
#include "event_container.h"

namespace mtm
{
class Schedule
{
private:
    std::list<BaseEvent*> event_list;
    void addEvent(const BaseEvent& event); //added const zeev 
    BaseEvent* findEventByDateAndName(const mtm::DateWrap& date, const std::string& name) const;
    void freeEventPointers();

public:
    Schedule();
    Schedule(const Schedule& schedule);
    ~Schedule();
    Schedule& operator=(const Schedule& schedule);
    void addEvents(const EventContainer& event_container);
    void registerToEvent(const mtm::DateWrap& date, const std::string& name, int student);
    void unregisterFromEvent(const mtm::DateWrap& date, const std::string& name, int student);
    void printAllEvents() const;
    void printMonthEvents(int month, int year) const;
    template <class Predicate>
    void printSomeEvents(Predicate predicate, bool verbose = false) const;
    void printEventDetails(const mtm::DateWrap& date, const std::string& name) const;
};

template <class Predicate>
void Schedule::printSomeEvents(Predicate predicate, bool verbose) const
{
    for (BaseEvent* event: this->event_list)
    {
        for (BaseEvent* event: this->event_list)
        {
            if(predicate(*event))
            {
                if(verbose)
                {
                    event->printLong(std::cout) << std::endl;
                }
                else
                {
                    event->printShort(std::cout) << std::endl;
                }
            }
        }
    }
}

#endif