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
    BaseEvent(mtm::DateWrap date, std::string name);
    virtual ~BaseEvent(){}
    virtual void registerParticipant(int participant);
    void unregisterParticipant(int participant);
    std::ostream& printShort(std::ostream& out) const;
    std::ostream& printLong(std::ostream& out) const;
    virtual BaseEvent* clone() const = 0; 
    bool operator<(const BaseEvent& event) const; 
    bool operator==(const BaseEvent& event) const;



    mtm::DateWrap getDate() const {return this->date;}  //make event container friend class maybe?
    std::string getName() const {return this->name;}
    void changeDate(int days_to_add)//TODO: move to ccp if final 
    {
        this->date+=days_to_add;
    }
};


    

#endif