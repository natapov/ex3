#include "date_wrap.h"
#include "assert.h"
using namespace mtm;
int main()
{
    bool result = true;
    int day = 11, day2 = 25, month = 1, month2 = 8, year = 2021, year2 = 1990;
    DateWrap date(day, month, year);
    DateWrap date2(date);
    DateWrap date3(day2, month2, year2);

    assert(date.day() == day);
    assert(date.month() == month);
    assert(date.year() == year);

    assert(date2.day() == day);
    assert(date2.month() == month);
    assert(date2.year() == year);

    date2 = date3;
    assert(date2.day() == day2);
    assert(date2.month() == month2);
    assert(date2.year() == year2);
    DateWrap date4(1, 1, 20);
    DateWrap date5(1, 1, 20);
    assert(date5++ == date4);
    return result;
}
