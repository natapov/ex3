#include "festival.h"
#include "exceptions.h"
using mtm::Festival;
using mtm::DateWrap;
using mtm::DateMismatch;
Festival::Festival(DateWrap date): EventContainer(), date(date){}
void Festival::add(const BaseEvent& event)
{
    if(this->date != event.getDate())
    {
        throw DateMismatch();
    }
    EventContainer::add(event);
}