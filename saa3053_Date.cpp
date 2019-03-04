#include "saa3053_Date.h"

bool Date::operator<(const Date &date_two) const 
{
		int check[3] = { this->month,  this->day, this->year };
		int check2[3] = { date_two.month, date_two.day,  date_two.year };

		for (int i = 0; i < 3; i++) {
				if (check[i] < check2[i])
						return true;
				else if (check[i] > check2[i])
						return false;
		}
		return false;
}

int Date::get_month() const
{
		return month;
}

int Date::get_year() const
{
		return year;
}

int Date::get_day() const
{
		return day;
}
string Date::to_string() const
{
				return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
}

void Date::set_date(int mon, int d, int y)
{
		month = mon;
		day = d;
		year = y;
}
