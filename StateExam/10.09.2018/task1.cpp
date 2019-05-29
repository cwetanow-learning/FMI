#include <iostream>

using namespace std;

bool isRowSorted(string row[], int rowSize)
{
    for(int i=1; i<rowSize; i++)
    {
        if(row[i] < row[i-1])
        {
            return false;
        }
    }

    return true;
}

void printWordLengts(string words)
{
    int counter = 0;
    for(int i=0; i< words.length(); i++)
    {
        if(words[i]==' ')
        {
            cout << counter << " ";
            counter= 0;
        }
        else
        {
            counter++;
        }
    }

    cout << counter << " ";
}

void revealPassword(string a[20][30], int m, int n)
{
    for(int i=0; i < m; i++)
    {
        if(isRowSorted(a[i],n))
        {
            string middleWords = a[i][n/2];

            printWordLengts(middleWords);
        }
    }
}

int main()
{
    string a[20][30] =
    {
        {"Алгебра", "Аналитична геометрия", "Математически анализ"},
        {"Увод в програмиранет", "Обектно-ориентирано програмиран", "Структури от данни и програмиране"},
        {"Бази от данни", "Изкуствен интелект", "Функционално програмиране"}
    };

    revealPassword(a,3,3);

    return 0;
}
