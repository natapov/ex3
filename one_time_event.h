#ifndef ONE_TIME_EVENT_H_
#define ONE_TIME_EVENT_H_

#include "event_container.h"
#include "date_wrap.h"
#include "exceptions.h"


namespace mtm
{
    template <typename EventType>
    class OneTimeEvent : public EventContainer
    {
    public:
        OneTimeEvent(DateWrap date, std::string name): EventContainer()
        {
            EventType event(date, name); //NOTE: THIS MEANS WE DON'T SUPPORT CUSTOM EVENT BECAUSE THE CONSTRUCTOR TAKES MORE VALUES 
            EventContainer::add(event);
        }
        void add(const BaseEvent& event) override{
            throw NotSupported();
        }
    };
}


#endif