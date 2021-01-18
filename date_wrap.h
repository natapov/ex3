#ifndef DATE_WARP_H_
#define DATE_WARP_H_

#include <iostream>
#include "exceptions.h"
namespace mtm
{
	class DateWrap;
}
extern "C"{
	#include "date.h"
}

class mtm::DateWrap{
	int day_data;
	int month_data;
	int year_data;
	Date turnIntoDate() const;
	int dateWrapCompare(const DateWrap& date) const;
	
public:
	static const int DAYS_IN_MONTH = 30;
	static const int MONTHS_IN_YEAR = 12;
	DateWrap(const DateWrap&) = default;
	~DateWrap() = default;
	DateWrap(int day, int month, int year);

	int day() const;
	int month() const;
	int year() const;

	bool operator==(const DateWrap& date) const;
	bool operator!=(const DateWrap& date) const;
	bool operator<=(const DateWrap& date) const;
	bool operator>=(const DateWrap& date) const;
	bool operator<(const DateWrap& date) const;
	bool operator>(const DateWrap& date) const;
	DateWrap operator++(int);
	DateWrap operator+=(int days);
	DateWrap operator+(int days) const;
	friend DateWrap operator+(int days, const DateWrap& date);
	friend std::ostream& operator<<(std::ostream& os, const DateWrap& date);
};
#endif