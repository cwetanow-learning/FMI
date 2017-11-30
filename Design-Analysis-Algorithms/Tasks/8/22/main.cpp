#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <string.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    priority_queue<int, vector<int>, greater<int>> numbers;
    int number;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &number);
        numbers.push(number);
    }

    while (!numbers.empty())
    {
        number = numbers.top();
        numbers.pop();
        printf("%d ", number);
    }

    return 0;
}