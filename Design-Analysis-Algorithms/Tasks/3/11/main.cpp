#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <string.h>
#include <limits>
using namespace std;

priority_queue<int, vector<int>, greater<int>> upper;
priority_queue<int> lower;

void push(int number)
{
    if (number >= upper.top())
    {
        upper.push(number);
    }
    else
    {
        lower.push(number);
    }

    if (upper.size() - lower.size() == 2)
    {
        lower.push(upper.top());
        upper.pop();
    }
    else if (lower.size() - upper.size() == 2)
    {
        upper.push(lower.top());
        lower.pop();
    }
}

double get_median()
{
    double median;

    if (upper.size() == lower.size())
    {
        median = upper.top();
        median = (median + lower.top()) / 2;
    }
    else if (upper.size() > lower.size())
    {
        median = upper.top();
    }
    else
    {
        median = lower.top();
    }

    return median;
}

int main()
{
    int n;
    scanf("%d", &n);

    upper.push(std::numeric_limits<int>::max());
    lower.push(std::numeric_limits<int>::min());

    int number;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &number);
        push(number);

        double median = get_median();
        printf("%.1f ", median);
    }

    return 0;
}