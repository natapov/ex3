#include "date_wrap.h"
#include <iostream>
#include "custom_event.h"
#include "open_event.h"
#include "closed_event.h"

#include "event_container.h"
using std::cout;
using std::endl;
using std::string;
using mtm::CustomEvent;
using mtm::OpenEvent;
using mtm::ClosedEvent;
using mtm::EventContainer;

using mtm::DateWrap;
struct Function
{
    bool operator()(int n){
        return n%2 == 0;
    }
};
int main()
{
    DateWrap date(1, 2, 3);
    string s = "Party";
    OpenEvent event("first event", date);
    event.registerParticipant(1234);
    event.registerParticipant(4321);
    event.registerParticipant(1);
    event.registerParticipant(2);
    event.registerParticipant(3);
    

    OpenEvent event3 = event;
    event3.registerParticipant(43921);
    event3.printLong(cout);
    event.printLong(cout);
    date+= 3245342;
    cout <<"TESTING CLOSED EVENT \n";
    ClosedEvent event4(s, date);
    event4.registerParticipant(1234);
    event4.registerParticipant(432);
    event4.addInvitee(24);
    event4.addInvitee(2);
    event4.printLong(cout);
    ClosedEvent event5 = event4;
    event5.registerParticipant(24);
    event5.registerParticipant(2);
    event4.printLong(cout);
    event5.printLong(cout);
    
    // cout <<"TESTING CUSTOM EVENT \n";
    // date+= 3245342;
    // Function f;
    // CustomEvent<Function> event1(s, date, f);
    
    // event1.registerParticipant(1234);
    // event1.registerParticipant(432);
    // event1.registerParticipant(24);
    // event1.registerParticipant(2);
    // event1.printLong(cout);
    // CustomEvent<Function> event3 = event1;
    // event3.registerParticipant(43920);
    // event3.registerParticipant(43921);
    // event3.printLong(cout);
    // event1.printLong(cout);
    // date+= 3245342;

    cout <<"TESTING EVENT CONTAINER \n";

    EventContainer container;
    container.add(event3);
    container.add(event4);
    container.add(event5);
    for(EventContainer::EventIterator iter = container.begin(); iter != container.end(); ++iter)
    {
        (*iter).printLong(cout);
    }

}
