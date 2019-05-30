#include <iostream>
#include <sstream>

using namespace std;

int findSpace(char terrain[][100], int m, int n, int row, int col, bool visited[][100])
{
    if(row == m || col<0 || col == n || visited[row][col])
    {
        return 0;
    }

    if(terrain[row][col]=='4')
    {
        cout << row << " "<< col<< endl;

        visited[row][col]=true;

        int leftTerrain = findSpace(terrain,m,n,row,col-1,visited);
        int rightTerrain = findSpace(terrain,m,n,row,col+1,visited);
        int downTerrain = findSpace(terrain,m,n,row+1,col,visited);

        return 1 + leftTerrain+rightTerrain+downTerrain;
    }

    return 0;
}

int findBiggestSpace(char terrain[][100], int m, int n)
{
    bool visited[100][100];

    int maxFoundSpace = 0;
    for(int row = 0; row < m; row++)
    {
        for(int col=0; col < n; col++)
        {
            if(terrain[row][col]=='4' && !visited[row][col])
            {
                int maxTerrainForArea = findSpace(terrain,m,n,row,col,visited);
cout << endl;

                maxFoundSpace = maxFoundSpace > maxTerrainForArea ? maxFoundSpace : maxTerrainForArea;
            }
        }
    }

    return maxFoundSpace;
}

int main()
{
    char terrain[][100] =
    {
        {'R','R','1','1','4','4'},
        {'1','R','R','R','4','4'},
        {'S','1','R','R','2','3'},
        {'4','4','S','S','R','R'}
    };

    cout << findBiggestSpace(terrain,4,6);

    return 0;
}
