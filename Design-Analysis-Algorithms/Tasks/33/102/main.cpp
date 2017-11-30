#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int number;
    cin >> number;

    int numbers[number];

    for (int i = 0; i < number; i++)
    {
        scanf("%d", &numbers[i]);
    }

    int count = 0;

    for (int i = 0; i < number; i++)
    {
        for (int j = i; j < number; j++)
        {
            if (numbers[i] > numbers[j])
            {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}