#include <exception>
#include "date_wrap.h"
using mtm::DateWrap;
using std::ostream;
using mtm::NegativeDays;
using mtm::InvalidDate;
using std::bad_alloc;
DateWrap::DateWrap(int day, int month, int year){
	if(day <= 0 || day > this->DAYS_IN_MONTH || month <= 0 || month > this->MONTHS_IN_YEAR)
	{
		throw InvalidDate();
	}
	day_data  = day;
	month_data= month;
	year_data = year;
}

int DateWrap::day() const{
		return day_data;
	}
int DateWrap::month() const{
		return month_data;
	}
int DateWrap::year() const{
		return year_data;
	}
Date DateWrap::turnIntoDate() const{
	return dateCreate(day_data, month_data, year_data);
}
int DateWrap::dateWrapCompare(const DateWrap& date) const{
	Date this_date = this->turnIntoDate();
	if(this_date == nullptr)
	{
		throw bad_alloc();
	}
	Date other_date = date.turnIntoDate();
	if(other_date == nullptr)
	{
		dateDestroy(this_date);
		throw bad_alloc();
	}
	int compare_result = dateCompare(this_date, other_date);
	dateDestroy(this_date);
	dateDestroy(other_date);
	return compare_result;
}
bool DateWrap::operator==(const DateWrap& date)const{
	return this->dateWrapCompare(date) == 0;
}
bool DateWrap::operator!=(const DateWrap& date)const{
	return this->dateWrapCompare(date) != 0;
}
bool DateWrap::operator<=(const DateWrap& date)const{
	return this->dateWrapCompare(date) <= 0;
}
bool DateWrap::operator>=(const DateWrap& date)const{
	return this->dateWrapCompare(date) >= 0;
}
bool DateWrap::operator<(const DateWrap& date)const{
	return this->dateWrapCompare(date) < 0;
}
bool DateWrap::operator>(const DateWrap& date)const{
	return this->dateWrapCompare(date) > 0;
}
DateWrap DateWrap::operator++(int)
{
	DateWrap tmp(*this);
	if(day_data < DAYS_IN_MONTH)
	{		
		day_data++;
		return tmp;
	}
	if(month_data < MONTHS_IN_YEAR)
	{
		month_data++;
		day_data = 1;
		return tmp;
	}
	year_data++;
	month_data = 1;
	day_data = 1;
	return tmp;
}

DateWrap DateWrap::operator+=(int days)
{
	if(days < 0)
	{
		throw NegativeDays();
	}
	for (int i = 0; i < days; i++)
	{
		(*this)++;
	}
	return *this;
}

DateWrap DateWrap::operator+(int days) const
{
	if(days < 0)
	{
		throw NegativeDays();
	}
	DateWrap copy(*this);
	return copy += days;
}
namespace mtm
{
	DateWrap operator+(int days, const DateWrap& date)
	{
		return date + days;
	}
	ostream& operator<<(ostream& os, const DateWrap& date)
	{
		os << date.day() << "/"  << date.month() << "/" << date.year();
		return os;
	}
}


