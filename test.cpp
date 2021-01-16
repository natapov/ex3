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

int main()
{
    DateWrap date(1, 2, 3);
    CanRegister can;
    bool ret = can(13);
    cout << ret << endl;
    string s = "Party";
    OpenEvent event(s, date);
    event.printLong(cout);

    CustomEvent event1(s, date, can);
    
    event1.printLong(cout);
   // CustomEvent event(s, date, can);
    /**
    DateWrap date1(1, 2, 3);
    DateWrap date2(1, 2, 2);
    bool result =(date == date1);
    cout << "result :"<< result << endl;
    result =(date == date2);
    cout << "result :"<< result << endl;
    return 0;
    **/
}
