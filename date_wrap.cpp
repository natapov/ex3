#include "date_wrap.h"

bool operator==(const DateWrap& date1, const DateWrap& date2)
{
	return date1.dateWrapCompare(date2) == 0;
}