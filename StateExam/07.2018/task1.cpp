#include <iostream>
#include <sstream>

using namespace std;

void swap(int* array, int firstIndex, int secondIndex)
{
    int temp = array[firstIndex];
    array[firstIndex]=array[secondIndex];
    array[secondIndex]=temp;
}

string convert(int a)
{
    ostringstream oss;
    oss.clear();
    oss << a;

    return oss.str();
}

int* sortLex(int* a, int n)
{
    bool isSorted = false;

    while(!isSorted)
    {
        isSorted=true;
        for(int i=0; i<n-1; i++)
        {
            string convertedA = convert(a[i]);
            string convertedb = convert(a[i+1]);

            if(convertedA > convertedb)
            {
                isSorted=false;
                swap(a,i,i+1);
            }
        }
    }

    return a;
}

int main()
{
    int a[] = {13,14,7,2018,9,0};

    int n = 6;

    int* sorted = sortLex(a,n);

    for(int i=0; i < n; i++)
    {
        cout << sorted[i] << ' ';
    }

    return 0;
}
