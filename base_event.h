#ifndef BASE_EVENT_H_
#define BASE_EVENT_H_
#include <ostream>
#include <string>

#include "date_wrap.h"
#include "sorted_list.h"

class BaseEvent
{
    string name;
    DateWrap date;
    List participants;
public:
    BaseEvent(std::string name, mtm::DateWrap date);
    void registerParticipant(int participant);
    void unregisterParticipant(int participant);
    std::ostream& printShort(std::ostream& out);
    std::ostream& printLong(std::ostream& out);
    BaseEvent* clone() const;
    


    //code to later add to real event iterator implementation
    // class EventIterator
    // {
    //     List::ListIterator iterator;
    //     public:
    //     EventIterator(ListIterator list): iterator(list){}
    //     EventIterator operator++()
    //     {
    //         this->list++;
    //     }
        
    // }

    // EventIterator begin()
    // {
    //     EventIterator(list.begin())
    // }
    
    
// }


#endif