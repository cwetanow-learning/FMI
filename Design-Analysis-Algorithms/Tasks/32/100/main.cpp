#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

struct Lex
{
    string number;

    const bool operator<(const Lex &other) const
    {
        int len = number.length();
        int otherLen = other.number.length();

        int smaller = (len > otherLen) ? otherLen : len;

        for (int i = 0; i < smaller; i++)
        {
            if (number[i] != other.number[i])
            {
                return number[i] > other.number[i];
            }
        }
        return false;
    }
};

int main()
{
    int n;
    scanf("%d\n", &n);

    priority_queue<Lex> numbers;
    string input;

    for (int i = 0; i < n; i++)
    {
        getline(cin, input);
        Lex lex;
        lex.number = input;
        numbers.push(lex);
    }

    while (!numbers.empty())
    {
        string number = numbers.top().number;
        cout << number << endl;
        numbers.pop();
    }

    return 0;
}