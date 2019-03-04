#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

//#include <ctime>
//#include <time.h>

class Date
{
public:
		Date(int month, int day, int year) : day(day), month(month), year(year) {};
		bool operator<(const Date& date_two) const;
		int get_month() const;
		int get_year() const;
		int get_day() const;
		string to_string() const;
		void set_date(int mon, int d, int y);

private:
		int year;
		int month;
		int day;
};

#endif // !DATE_H
