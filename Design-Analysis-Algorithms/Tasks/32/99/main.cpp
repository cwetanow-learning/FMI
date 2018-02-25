#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

void quicksort(string chars, int leftIndex, int rightIndex)
{
    int i = leftIndex;
    int j = rightIndex;

    int pivot = chars[(leftIndex + rightIndex) / 2];

    while (i <= j)
    {
        while (chars[i] < pivot)
        {
            i++;
        }

        while (chars[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            char temp = chars[i];
            chars[i] = chars[j];
            chars[j] = temp;

            i++;
            j--;
        }
    }

    if (leftIndex < j)
    {
        quicksort(chars, leftIndex, j);
    }

    if (rightIndex > i)
    {
        quicksort(chars, i, rightIndex);
    }
}

struct Date
{
  public:
    int date;
    int month;
    int year;
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

        return index > other.index;
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    int date, month, year;

    priority_queue<Date> dates;

    for (int i = 0; i < n; i++)
    {
        char dot1;
        char dot2;

        cin >> date >> dot1 >> month >> dot2 >> year;

        Date dateType;
        dateType.date = date;
        dateType.month = month;
        dateType.year = year;
        dateType.index = i + 1;

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