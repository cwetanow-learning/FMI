#include <iostream>
#include <sstream>

using namespace std;

void evolve(char terrain[][100], int m, int n)
{
    char  newTerrain[100][100];

    for(int row =0; row < m; row++)
    {
        for(int col=0; col < n; col++)
        {
            if(terrain[row][col]=='1')
            {
                newTerrain[row][col]='2';
            }
            else if(terrain[row][col]=='2')
            {
                newTerrain[row][col]='3';
            }
            else if(terrain[row][col]=='3')
            {
                newTerrain[row][col]='4';
            }
            else if(terrain[row][col]=='4')
            {
                int counter = 0;

                for(int i=-1; i<2; i++)
                {
                    if(row+i <0 || row+i == m)
                    {
                        continue;
                    }

                    for(int j=-1; j<2; j++)
                    {
                        if(j==0 && i ==0)
                        {
                            continue;
                        }

                        if(col+j <0 || col+j == n)
                        {
                            continue;
                        }

                        if(terrain[row+i][col+j] == '4')
                        {
                            counter++;
                        }
                    }
                }

                if(counter >=3)
                {
                    newTerrain[row][col]='3';
                }
                else
                {
                    newTerrain[row][col]=terrain[row][col];
                }
            }
            else
            {
                newTerrain[row][col]=terrain[row][col];
            }
        }
    }

    for(int i =0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            terrain[i][j] = newTerrain[i][j];
            cout << terrain[i][j]  << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void passYears(char terrain[][100], int m, int n, int years)
{
    for(int i=0; i<years; i++)
    {
        cout << i +1 << endl;
        evolve(terrain,m,n);
    }

}

int main()
{
    char terrain[][100] =
    {
        {'R','R','1','1','2','2'},
        {'1','R','R','R','1','2'},
        {'S','1','R','R','2','3'},
        {'4','4','S','S','R','R'}
    };

    passYears(terrain,4,6,10);

    return 0;
}
