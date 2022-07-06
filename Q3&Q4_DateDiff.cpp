#include <iostream>
#include <cstdlib>
using namespace std;


class Date {
public:
    Date(int d, int m, int y);
    void set_date(int d, int m, int y);
    void print_date();
    void inc_one_day();
    bool equals(Date d);

    int get_day() const { return day; }
    int get_month() const { return month; }
    int get_year() const { return year; }

    int compare(const Date &d);
private:
    int day;
    int month;
    int year;
};

int Date::compare(const Date &d) {
    if (year > d.get_year()) return 1;
    if (year < d.get_year()) return -1;
    if (month > d.get_month()) return 1;
    if (month < d.get_month()) return -1;
    if (day > d.get_day()) return 1;
    if (day < d.get_day()) return -1;
    return 0;
}


Date::Date(int d, int m, int y)
{
    set_date(d, m, y);
}

bool is_leap_year(int year)
{
    int r = year % 33;
    return r==1 || r==5 || r==9 || r==13 || r==17 || r==22 || r==26 || r==30;
}

int days_of_month(int m, int y)
{
    if (m < 7)
        return 31;
    else if (m < 12)
        return 30;
    else if (m == 12)
        return is_leap_year(y) ? 30 : 29;
    else
        abort();
}

void Date::set_date(int d, int m, int y)
{
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > days_of_month(m, y))
        abort();

    day = d;
    month = m;
    year = y;
}

void Date::inc_one_day()
{
    day++;
    if (day > days_of_month(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void Date::print_date()
{
    cout << day << '/' << month << '/' << year << endl;
}

bool Date::equals(Date d) {
    return day == d.day && 
           month == d.month && 
	       year == d.year;
}

int days_between(Date d1, Date d2) {
    Date &min = d1.compare(d2) < 0 ? d1 : d2;
    int count = 1;
    while (!d1.equals(d2)) {
        min.inc_one_day();
        count++;
    }
    return count;
}

int main()
{
    Date bd(31, 6, 1352);
    Date today(10, 12, 1391);
    cout << days_between(today, bd) << endl;



    Date d1(1, 1, 1352);
    Date d2(1, 1, 1352);
    Date d3(1, 1, 1353);
    cout << "d1  :  ";
    d1.print_date();
    cout << "d2  :  ";
    d2.print_date();
    cout << "d3  :  ";
    d3.print_date();

    cout << "d1.compare(d2)   ==   " << d1.compare(d2) << endl;
    cout << "d1.compare(d3)   ==   " << d1.compare(d3) << endl;
    cout << "d3.compare(d1)   ==   " << d3.compare(d1) << endl;
}