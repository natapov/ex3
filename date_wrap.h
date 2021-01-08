#ifndef DATE_WARP_H_
#define DATE_WARP_H_

#include "date.h"
class DateWrap
{
	//I think we should keep the data here and use Date functions only 
	//for comparisons
	int day_data;
	int month_data;
	int year_data;
	Date turnIntoDate() const
	{
		return dateCreate(day_data, month_data, year_data);
	}
	int dateWrapCompare(const DateWrap& date) const
	{
		return dateCompare(this->turnIntoDate(), date.turnIntoDate());
	}
public:
	DateWrap(int day, int month, int year): day_data(day), month_data(month), year_data(year){}
	int day() const
	{
		return day_data;
	}
	int month() const
	{
		return month_data;
	}
	int year() const
	{
		return year_data;
	}
	//operator fun
	friend bool operator==(const DateWrap&, const DateWrap&);
};
#endif