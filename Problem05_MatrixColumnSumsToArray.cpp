// problem_05_Matrix Column Sums To-1d Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int RandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void FillRandomMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintTheRandomMatrix(const int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3) << matrix[i][j] << "   ";
        }
        cout << "\n";
    }
}

int ColumnSum(const int matrix[3][3], short colIndex, short rows)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        sum += matrix[i][colIndex];
    }
    return sum;
}

void SumMatrixColumnsInArray(int columnSums[3], const int matrix[3][3], short rows, short cols)
{
    for (short j = 0; j < cols; j++)
    {
        columnSums[j] = ColumnSum(matrix, j, rows);
    }
}

void PrintColumnSums(const int columnSums[3], short cols)
{
    for (short j = 0; j < cols; j++)
    {
        cout << "Column " << j + 1 << " = " << columnSums[j] << "\n";
    }
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int randomNumber[3][3];
    int columnSums[3];

    FillRandomMatrix(randomNumber, 3, 3);

    cout << "The 3x3 random matrix is:\n\n";
    PrintTheRandomMatrix(randomNumber, 3, 3);

    SumMatrixColumnsInArray(columnSums, randomNumber, 3, 3);

    cout << "\n\nThe following are the sums of each column in the matrix:\n\n";
    PrintColumnSums(columnSums, 3);

    return 0;
}
