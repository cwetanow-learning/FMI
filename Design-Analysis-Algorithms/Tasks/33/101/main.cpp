#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    char operation;
    int number;

    priority_queue<int> numbers;

    while (true)
    {
        scanf("%c %d[^\n]%", &operation, &number);

        if (operation == 'A')
        {
            numbers.push(number);

            continue;
        }

        if (operation == 'R')
        {
            if (numbers.empty())
            {
                printf("Not available\n");
            }
            else
            {
                printf("%d\n", numbers.top());
                numbers.pop();
            }

            continue;
        }

        if (operation == 'L')
        {
            if (numbers.empty())
            {
                printf("Not available\n");
            }
            else
            {
                printf("%d\n", numbers.top());
            }

            continue;
        }

        if (operation == 'Q')
        {
            break;
        }
    }

    return 0;
}