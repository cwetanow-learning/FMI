#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    int n, l, r;

    scanf("%d %d %d\n", &n, &l, &r);

    priority_queue<int> numbers;

    int number;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &number);
        numbers.push(number);
    }

    int biggerSum = 0;
    int rangeSum = 0;

    int right;
    int left;

    for (int i = 0; i < r - 1; i++)
    {
        number = numbers.top();
        biggerSum += number;
        numbers.pop();
    }

    right = numbers.top();
    numbers.pop();

    for (int i = 0; i < l - r - 1; i++)
    {
        number = numbers.top();
        rangeSum += number;
        numbers.pop();
    }

    left = numbers.top();
    numbers.pop();

    printf("%d %d %d", left, right, rangeSum - biggerSum);

    return 0;
}