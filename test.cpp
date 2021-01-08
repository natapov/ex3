#include "date_wrap.h"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
    DateWrap date(1, 2, 3);
    DateWrap date1(1, 2, 3);
    DateWrap date2(1, 2, 2);
    bool result =(date == date1);
    cout << "result :"<< result << endl;
    result =(date == date2);
    cout << "result :"<< result << endl;
   return 0;
}
