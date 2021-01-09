#include "date_wrap.h"



int DateWrap::dateWrapCompare(const DateWrap& date) const{
	return dateCompare(this->turnIntoDate(), date.turnIntoDate());
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
