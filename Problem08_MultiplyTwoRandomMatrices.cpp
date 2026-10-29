// Problem 08 - Multiply Two Random Matrices
//
// Fills two 3x3 matrices with random numbers (1-10) and multiplies them
// element by element: result[i][j] = matrix1[i][j] * matrix2[i][j].
// Note: this is not the mathematical matrix product.

// problem_08_Multiply Two Random Matrices.cpp

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

void printTheRandomMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            printf("%0*d    ", 2, matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int matrix1[3][3], int matrix2[3][3], int result[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int matrix1[3][3];
    int matrix2[3][3];
    int multiplicationResult[3][3];

    fillRandomMatrix(matrix1, 3, 3);
    fillRandomMatrix(matrix2, 3, 3);

    cout << "Matrix 1:\n\n";
    printTheRandomMatrix(matrix1, 3, 3);

    cout << "\nMatrix 2:\n\n";
    printTheRandomMatrix(matrix2, 3, 3);

    cout << "\nMultiplication Result:\n\n";
    multiplyMatrices(matrix1, matrix2, multiplicationResult, 3, 3);
    printTheRandomMatrix(multiplicationResult, 3, 3);

    return 0;
}
