// problem_17_check_given_number_isExists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
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
            matrix[i][j] = randomNumber(1, 100);
        }
    }
}

void printMatrix(const int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            printf(" %0*d  ", 2, matrix[i][j]);
        }
        cout << "\n";
    }
}

bool doesNumberExist(const int matrix[3][3], short rows, short cols, int numberToFind)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] == numberToFind)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int matrix1[3][3];
    fillRandomMatrix(matrix1, 3, 3);

    cout << "Random matrix numbers\n\n";
    printMatrix(matrix1, 3, 3);

    int number;
    cout << "\nWhat's the number do you want to exist: ";
    cin >> number;

    bool isFound = doesNumberExist(matrix1, 3, 3, number);

    cout << "\nThe number " << number << " is " << (isFound ? "found" : "not found") << ".\n";

    return 0;
}

