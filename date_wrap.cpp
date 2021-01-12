#include "date_wrap.h"
const int DAYS_IN_MONTH = 30;
const int MONTHS_IN_YEAR = 12;
using mtm::DateWrap;

DateWrap::DateWrap(int day, int month, int year): day_data(day), month_data(month), year_data(year){}

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
	Date other_date = date.turnIntoDate();
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
	if(day_data < DAYS_IN_MONTH)
	{
		day_data++;
		return *this;
	}
	if(month_data < MONTHS_IN_YEAR)
	{
		month_data++;
		day_data = 1;
		return *this;
	}
	year_data++;
	month_data = 1;
	day_data = 1;
	return *this;
}

DateWrap DateWrap::operator+=(int days)
{
	for (int i = 0; i < days; i++)
	{
		(*this)++;
	}
	return *this;
}

DateWrap DateWrap::operator+(int days) const
{
	DateWrap copy(*this);
	return copy+=days;
}

DateWrap operator+(int days, const DateWrap& date)
{
	return date + days;
}
ostream& operator<<(ostream& os, const DateWrap& date)
{
	os << date.day() << "/"  << date.month() << "/" << date.year();
	return os;
}

