// problem_11_Compare.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int sumOfMatrixElements(const int matrix[3][3], short rows, short cols)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}


bool areEqualMatricesBySum(const int matrix1[3][3], const int matrix2[3][3], short rows, short cols)
{
    return (sumOfMatrixElements(matrix1, rows, cols) == sumOfMatrixElements(matrix2, rows, cols));
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

   
    if (areEqualMatricesBySum(matrix1, matrix2, 3, 3))
        cout << "\nYes, the two matrices are equal by sum.\n";
    else
        cout << "\nNo, the matrices are NOT equal by sum.\n";

    return 0;
}
