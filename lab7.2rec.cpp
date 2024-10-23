#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High, int i, int j); 
void Print(int** a, const int rowCount, const int colCount, int i, int j);
int FindMaxSum(int** a, const int rowCount, const int colCount, int j = 0);
int FindMaxInColumn(int** a, const int rowCount, int maxInColumn, int currentMax, int j, int i);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -26;
    int High = 23;
    int rowCount = 8;
    int colCount = 6; 
    int** a = new int* [rowCount];
    cout << "Massive: " << endl;    
    for (int i = 0; i < rowCount; i++)

        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High, 0, 0);
    Print(a, rowCount, colCount, 0, 0);
    int maxSum = FindMaxSum(a, rowCount, colCount);
    cout << "Sum: " << maxSum << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, 
    const int Low, const int High, int i, int j) 
{
    if (i < rowCount) 
    {
        if (j < colCount) 
        {
         
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, rowCount, colCount, Low, High, i, j + 1);
        }
        else
        {
            Create(a, rowCount, colCount, Low, High, i + 1, 0);
        }
    }
}

void Print(int** a, const int rowCount, const int colCount, int i, int j) 
{
    if (i < rowCount) 
    {
        if (j < colCount)  
        {
            cout << setw(4) << a[i][j]; 
            Print(a, rowCount, colCount, i, j + 1);
        }
        else
        {
             cout  <<  endl; 
            Print(a, rowCount, colCount, i + 1, 0);
        }
    }
    else {
        cout  << endl;  
    }
}

int FindMaxSum(int** a, const int rowCount, const int colCount, int j)
{
    if (j >= colCount) {
        return 0;
    }

    int maxSumInColumn = 0;
    if (j % 2 != 0) {
        maxSumInColumn = FindMaxInColumn(a, rowCount, 0, a[0][j], j, 1);
    }

    return maxSumInColumn + FindMaxSum(a, rowCount, colCount, j + 1); 
}

int FindMaxInColumn(int** a, const int rowCount, int maxInColumn, int currentMax, int j, int i) 
{
    if (i >= rowCount)
    {
        return maxInColumn;
    }

    if (a[i][j] > currentMax) 
    {
        currentMax = a[i][j];
    }

    return FindMaxInColumn(a, rowCount, currentMax, currentMax, j, i + 1);
}
