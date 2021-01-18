#include "date_wrap.h"
#include <iostream>
#include "custom_event.h"
#include "open_event.h"
#include "closed_event.h"
#include "event_container.h"
#include "festival.h"
using std::cout;
using std::endl;
// using std::string;
// using mtm::CustomEvent;
// using mtm::OpenEvent;
// using mtm::ClosedEvent;
// using mtm::EventContainer;
// using mtm::BaseEvent;
// using mtm::DateWrap;
using namespace mtm;
struct Function
{
    bool operator()(int n){
        return n%2 == 0;
    }
};
int main()
{
    DateWrap date(1, 2, 3);
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
    
    cout <<"TESTING CLOSED EVENT \n";
    date++;
    ClosedEvent event4("This is a closed event", date);
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
    
    cout <<"TESTING CUSTOM EVENT \n";
    date++;
    Function f;
    CustomEvent<Function> event1("This is a custom event", date, f);
    
    event1.registerParticipant(1234);
    event1.registerParticipant(432);
    event1.registerParticipant(24);
    event1.registerParticipant(2);
    event1.printLong(cout);
    // CustomEvent<Function> event3 = event1;
    // event3.registerParticipant(43920);
    // event3.registerParticipant(43921);
    // event3.printLong(cout);
    // event1.printLong(cout);
    // date+= 3245342;

    // cout <<"TESTING EVENT CONTAINER \n";

    // EventContainer ec;
    // ec.add(event3);
    // ec.add(event4);
    // ec.add(event5);
    // ec.add(event1);
    // for(EventContainer::EventIterator iter = ec.begin(); iter != ec.end(); ++iter)
    // {
    //     (*iter).registerParticipant(111112);
    //     (*iter).printLong(cout);
    // }
    // EventContainer::EventIterator it = ec.begin();
    // EventContainer::EventIterator it_end = ec.end();
    // BaseEvent& ev = *it; // `ev` is the first event stored in `ec`
    // ev.printShort(cout); // print short description of 1st event
    // (*it).printShort(cout); // same output as previous line
    // ++it;
    // (*it).printShort(cout); // print short description of 2nd event
    // std::cout << (it == it_end) << std::endl; // print "0"
    // std::cout << (it != it_end) << std::endl; // print "1"
    // ++it;
    // std::cout << (it == it_end) << std::endl; // print "1"
    // std::cout << (it != it_end) << std::endl; // print "0"

    cout <<"TESTING FESTIVAL \n";
    DateWrap date_festival(12, 12, 123);
    OpenEvent eventf("Open event in festival", date_festival);
    eventf.registerParticipant(1234);
    eventf.registerParticipant(4321);
    eventf.registerParticipant(1);
    eventf.registerParticipant(2);
    eventf.registerParticipant(3);


    ClosedEvent event2f("This is a closed event in festival", date_festival);
    event2f.registerParticipant(1234);
    event2f.registerParticipant(432);
    event2f.addInvitee(24);
    event2f.addInvitee(2);

    Function f1;
    
    Festival fest(date_festival);
    fest.add(eventf);
    fest.add(event2f);
    
    date_festival++;//THIS SHOULD CAUSE EXCEPION !!
    CustomEvent<Function> event1f("This is a custom event in festival", date_festival, f1);
    event1f.registerParticipant(1234);
    event1f.registerParticipant(432);
    event1f.registerParticipant(24);
    event1f.registerParticipant(2);
    
    
    fest.add(event1f);

    EventContainer& ec = fest;
    EventContainer::EventIterator it = ec.begin();
    EventContainer::EventIterator it_end = ec.end();

    for(EventContainer::EventIterator iter = ec.begin(); iter != ec.end(); ++iter)
    {
      //  (*iter).registerParticipant(111112);
        (*iter).printLong(cout);
    }
    std::cout << (it == it_end) << std::endl; // print "0"
    std::cout << (it != it_end) << std::endl; // print "1"
    ++it;
    std::cout << (it == it_end) << std::endl; // print "1"
    std::cout << (it != it_end) << std::endl; // print "0"
   
}
