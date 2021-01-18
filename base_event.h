#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_

#include <iostream>
#include <string>

#include "date_wrap.h"
#include "list.h"
#include "exceptions.h"

namespace mtm
{
    class BaseEvent;
}
class mtm::BaseEvent
{
protected:
    std::string name;
    mtm::DateWrap date;
    List<int> participants;
public:
    const static int MIN_STUDENT = 1;
    const static int MAX_STUDENT = 1234567890;
    BaseEvent(std::string name, mtm::DateWrap date);
    virtual ~BaseEvent(){}
    virtual void registerParticipant(int participant);
    void unregisterParticipant(int participant);
    std::ostream& printShort(std::ostream& out) const;
    std::ostream& printLong(std::ostream& out) const;
    virtual BaseEvent* clone() const = 0; 
    bool operator<(const BaseEvent& event) const; 
    bool operator==(const BaseEvent& event) const;



    mtm::DateWrap getDate(){return date;} //make event container friend class maybe?
    void changeDate(int days_to_add)//TODO: move to ccp if final 
    {
        this->date+=days_to_add;
    }
};


    

#endif