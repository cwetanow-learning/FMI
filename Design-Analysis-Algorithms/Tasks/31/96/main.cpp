#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int input;

    vector<double> squares;
    int counter = 0;

    while (1 == scanf("%d", &input))
    {
        double result = sqrt(input);

        squares.push_back(result);
        counter++;
    }

    double current;
    while (counter > 0)
    {
        current = squares.back();
        printf("%lf\n", current);
        squares.pop_back();
        counter--;
    }

    return 0;
}