#include "base_event.h"

using std::string; //I think these should be moved to cpp file zeev
using std::ostream;
using std::endl;
using mtm::DateWrap;

BaseEvent::BaseEvent(string name, DateWrap date): name(name), date(date), participants(){}
void BaseEvent::registerParticipant(int participant)
{
    participants.add(participant);
    
}

void BaseEvent::unregisterParticipant(int participant)
{
    participants.remove(participant);
}

BaseEvent* BaseEvent::clone() const
{
    BaseEvent clone(this->name, this->date);
    clone.participants = this->participants;
    return &clone;
}
ostream& BaseEvent::printShort(ostream& out)
{
    out << name << " " << date;
    return out;
}

ostream& BaseEvent::printLong(ostream& out)
{
    printShort(out) << endl;
    List::ListIterator current = participants.begin();
    List::ListIterator end = participants.end();
    while(current != end)
    {
        out << *current << endl;
        ++current;
    }
    return out;
}