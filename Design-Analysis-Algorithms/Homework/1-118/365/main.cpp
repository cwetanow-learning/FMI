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

int rangeSize = 57;

// Function to sort arr[] of size n using bucket sort
void bucketSort(string input, int arr[])
{
    for (int i = 0; i < rangeSize; i++)
    {
        arr[i] = 0;
    }

    for (int i = 0; i < input.size(); i++)
    {
        int index = input[i] - 65;
        arr[index]++;
    }
}

struct Str
{
    string str;
    int sorted[57];
    int index;

    const bool operator<(const Str &other) const
    {
        for (int i = 0; i < rangeSize; i++)
        {
            if ((i > 25 && i < 30) || i == 31)
            {
                continue;
            }

            int left = sorted[i];
            int right = other.sorted[i];

            if (left != right)
            {
                return left < right;
            }
        }

        return index > other.index;
    }
};

int main()
{
    int n;
    scanf("%d", &n);

    priority_queue<Str> inputs;

    char input[1000000];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", input);

        Str str;
        str.str = input;
        str.index = i;

        bucketSort(input, str.sorted);

        inputs.push(str);
    }

    while (!inputs.empty())
    {
        string str = inputs.top().str;
        cout << str << endl;

        inputs.pop();
    }
}