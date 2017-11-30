#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

struct Date
{
  public:
    int date;
    int month;
    int year;
    int hour;
    int minute;
    int second;

    int index;

    const bool operator<(const Date &other) const
    {
        if (year != other.year)
        {
            return year > other.year;
        }

        if (month != other.month)
        {
            return month > other.month;
        }

        if (date != other.date)
        {
            return date > other.date;
        }

        if (hour != other.hour)
        {
            return month > other.month;
        }

        if (minute != other.minute)
        {
            return month > other.month;
        }

        if (second != other.second)
        {
            return month > other.month;
        }

        return index > other.index;
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    int date, month, year, minute, second, hour;

    priority_queue<Date> dates;

    for (int i = 0; i < n; i++)
    {
        char dot1;
        char dot2;
        char twoDots1;
        char twoDots2;
        char space;

        cin >> hour >> twoDots1 >> minute >> twoDots2 >> second >> space >> date >> dot1 >> month >> dot2 >> year;

        Date dateType;
        dateType.date = date;
        dateType.month = month;
        dateType.year = year;
        dateType.minute = minute;
        dateType.second = second;
        dateType.index = i + 1;
        dateType.hour = hour;

        dates.push(dateType);
    }

    while (!dates.empty())
    {
        Date date = dates.top();
        printf("%d\n", date.index);

        dates.pop();
    }

    return 0;
}