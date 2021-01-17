#include "base_event.h"

using std::string; //I think these should be moved to cpp file zeev
using std::ostream;
using std::endl;
using mtm::BaseEvent;
using mtm::DateWrap;
using mtm::AlreadyRegistered;
using mtm::InvalidStudent;

BaseEvent::BaseEvent(string name, DateWrap date): name(name), date(date), participants(){}
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
    participants.remove(participant);
}
/**
BaseEvent* BaseEvent::clone() const
{
    BaseEvent* cloned_event = new BaseEvent(this->name, this->date);
    cloned_event->participants = this->participants;
    return cloned_event;
}
**/
ostream& BaseEvent::printShort(ostream& out) const
{
    out << name << " " << date;
    return out;
}

ostream& BaseEvent::printLong(ostream& out) const
{
    printShort(out) << endl;
    List<int>::ListIterator current = participants.begin();
    List<int>::ListIterator end = participants.end();
    
    while(current != end)
    {
        out << *current << endl;
        ++current;
    }
    return out;
}

/**
bool BaseEvent::operator<(const BaseEvent event) const
{
    return this->date < event.date;
}
bool BaseEvent::operator==(const BaseEvent event) const //currently compares name, this whill only be uset in List::contains this can change depends on what we need
{
    return this->name == event.name;
}
**/