#include "base_event.h"

using std::string; 
using std::ostream;
using std::endl;
using mtm::BaseEvent;
using mtm::DateWrap;
using mtm::AlreadyRegistered;
using mtm::InvalidStudent;

BaseEvent::BaseEvent(const mtm::DateWrap& date, const std::string& name): name(name), date(date), participants(){}
void BaseEvent::registerParticipant(int participant)
{
    if (participant > this->MAX_STUDENT || participant < this->MIN_STUDENT)
    {
        throw InvalidStudent();
    }
    if (this->participants.contains(participant))
    {
        throw AlreadyRegistered();
    }
    participants.add(participant);
}

void BaseEvent::unregisterParticipant(int participant)
{
    if (participant > this->MAX_STUDENT || participant < this->MIN_STUDENT)
    {
        throw InvalidStudent();
    }
    if(!this->participants.contains(participant))
    {
        throw NotRegistered();
    }
    participants.remove(participant);
}

ostream& BaseEvent::printShort(ostream& out) const
{
    out << name << " " << date << endl;
    return out;
}

ostream& BaseEvent::printLong(ostream& out) const
{
    printShort(out);
    List<int>::ListIterator current = participants.begin();
    List<int>::ListIterator end = participants.end();
    
    while(current != end)
    {
        out << *current << endl;
        ++current;
    }
    return out;
}

bool BaseEvent::operator<(const BaseEvent& event) const
{
    if(this->date !=  event.date)
    {
        return this->date < event.date;
    }
    return(this->name < event.name);
}
bool BaseEvent::operator==(const BaseEvent& event) const 
{
    return (this->name == event.name) && (this->date == event.date);
}

mtm::DateWrap BaseEvent::getDate() const 
{
    return this->date;
}  
std::string BaseEvent::getName() const
{
    return this->name;
}
void BaseEvent::changeDate(int days_to_add)
{
    this->date+=days_to_add;
}