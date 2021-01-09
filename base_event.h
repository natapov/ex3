#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_
#include <ostream>
#include <string>

#include "date_wrap.h"

using std::string
using std::ostream

class BaseEvent
{
    string name;
    DateWrap date;
    List participants;
public:
    BaseEvent(string name, DateWrap date);
    void registerParticipant(int participent);
    void unregisterParticipant(int participent);
    ostream& printShort(ostream& out);
    ostream& printLong(ostream& out);
    BaseEvent* clone();}




#endif