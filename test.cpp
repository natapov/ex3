#include "date_wrap.h"
#include <iostream>
#include "custom_event.h"
#include "open_event.h"
using std::cout;
using std::endl;
using std::string;
using mtm::CustomEvent;
using mtm::OpenEvent;
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
    OpenEvent event(s, date);
    event.registerParticipant(1234);
    event.registerParticipant(4321);
    event.registerParticipant(1);
    event.registerParticipant(2);
    event.printLong(cout);
    date+= 3245342;
    Function f;
    CustomEvent<Function> event1(s, date, f);
    
    event1.registerParticipant(1234);
    event1.registerParticipant(432);
    event1.registerParticipant(024);
    event1.registerParticipant(2);
    event1.printLong(cout);

 

}
