// problem_09_Print Middle Roe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int randomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void fillRandomMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = randomNumber(1, 10);
        }
    }
}

void printTheRandomMatrix(const int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            printf("%0*d    ", 2, matrix[i][j]);
        }
        cout << "\n";
    }
}

void printMiddleRow(const int matrix[3][3], short rows, short cols)
{
    short middleRowIndex = rows / 2;

    for (short j = 0; j < cols; j++)
    {
        printf("%0*d    ", 2, matrix[middleRowIndex][j]);
    }
    cout << "\n";
}

void printMiddleColumn(const int matrix[3][3], short rows, short cols)
{
    short middleColIndex = cols / 2;

    for (short i = 0; i < rows; i++)
    {
        printf("%0*d    ", 2, matrix[i][middleColIndex]);
    }
    cout << "\n";
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int matrix[3][3];

    fillRandomMatrix(matrix, 3, 3);
    printTheRandomMatrix(matrix, 3, 3);

    cout << "\nMiddle Row:\n";
    printMiddleRow(matrix, 3, 3);

    cout << "\nMiddle Column:\n";
    printMiddleColumn(matrix, 3, 3);

    return 0;
}

