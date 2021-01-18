#ifndef RECURRING_EVENT_H_
#define RECURRING_EVENT_H_

#include "event_container.h"
#include "date_wrap.h"
#include "exceptions.h"
#include "open_event.h"//TEMPORARY

namespace mtm{

typedef OpenEvent EventType;
class RecurringEvent : public EventContainer
{
public:
    RecurringEvent(DateWrap date, std::string name, int num_occurrences, int interval_days): EventContainer()
    {
        if(num_occurrences <=0)
        {
            throw InvalidNumber();
        }
        if(interval_days <= 0)
        {
            throw InvalidInterval();
        }

        EventType event(name, date); //NOTE: THIS MEANS WE DON'T SUPPORT CUSTOM EVENT BECAUSE THE CONSTRUCTOR TAKES MORE VALUES zeev
        for(int i = 0; i < num_occurrences; i++)
        {
            EventContainer::add(event);

            event.changeDate(interval_days);
        }
    }
    void add(BaseEvent& event) override
    {
        throw NotSupported();
    }
};
}
#endif