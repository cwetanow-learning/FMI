#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int getFood(unsigned long long index, unsigned long long left, unsigned long long right, int current)
{
    unsigned long long size = (right - left) / 3 + 1;

    if (right == left)
    {
        return current + 1;
    }

    current++;

    if (index >= size && index < size * 2)
    {
        return current;
    }

    if (index >= size * 2)
    {
        index = right - left - index;
    }

    return getFood(index, left, size - 1, current);
}

int main()
{
    int n, p;

    scanf("%d %d\n", &p, &n);

    unsigned long long count = 3;

    for (int i = 0; i < p - 1; i++)
    {
        count *= 3;
    }

    unsigned long long number;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &number);
        int amount = getFood(number - 1, 0, count - 1, 0);

        printf("%d\n", amount);
    }

    return 0;
}