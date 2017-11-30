#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int m, n, k;

    scanf("%d %d %d", &m, &n, &k);

    int first[m][n];
    int second[n][k];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> first[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> second[i][j];
        }
    }

    long mult[m][k];

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < k; ++j)
        {
            mult[i][j] = 0;
            for (int z = 0; z < n; ++z)
            {
                mult[i][j] += first[i][z] * second[z][j];
            }
        }

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < k; ++j)
        {
            if (j != 0)
            {
                cout << " ";
            }
            cout << mult[i][j];
            if (j == k - 1)
                cout << endl;
        }

    return 0;
}