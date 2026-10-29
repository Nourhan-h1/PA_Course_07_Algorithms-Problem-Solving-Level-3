// Problem 12 - Compare Typical Matrices
//
// Two matrices are "typical" when every element is equal to the element in
// the same position of the other matrix. Both matrices are random (1-10).

// problem_12_compare_typical_matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

bool areTypicalMatrices(const int matrix1[3][3], const int matrix2[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
                return false;
        }
    }
    return true;
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int matrix1[3][3];
    int matrix2[3][3];

    fillRandomMatrix(matrix1, 3, 3);
    cout << "Matrix 1:\n\n";
    printTheRandomMatrix(matrix1, 3, 3);

    fillRandomMatrix(matrix2, 3, 3);
    cout << "\nMatrix 2:\n\n";
    printTheRandomMatrix(matrix2, 3, 3);

    if (areTypicalMatrices(matrix1, matrix2, 3, 3))
        cout << "\nYes, the two matrices are typical (identical).\n";
    else
        cout << "\nNo, the matrices are NOT typical (different).\n";

    return 0;
}
