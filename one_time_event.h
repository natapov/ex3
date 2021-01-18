#ifndef ONE_TIME_EVENT_H_
#define ONE_TIME_EVENT_H_

#include "event_container.h"
//#include "date_wrap.h"
#include "exceptions.h"
#include "open_event.h"//TEMPORARY
#include "date_wrap.h"


namespace mtm
{
    typedef OpenEvent EventType
    class mtm::OneTimeEvent : public mtm::EventContainer
    {
    public:
        OpenEvent(DateWrap date, )
        void add(BaseEvent& event) override;

    }
}

#endif