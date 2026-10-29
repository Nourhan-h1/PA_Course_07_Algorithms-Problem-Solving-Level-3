// Problem 14 - Scalar Matrix Check
//
// A matrix is scalar when all elements on the main diagonal are equal and
// every other element is 0. The first diagonal element is the reference value.
// The matrix is hard-coded in main().

// problem_14_check_matrix_is_scalar_or_not.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

void printMatrix(const int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(2) << matrix[i][j] << "    ";
        }
        cout << "\n";
    }
}

bool isScalarMatrix(const int matrix[3][3], short rows, short cols)
{
    int firstDiagElement = matrix[0][0];

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            //check for diagonals element
            if (i == j && matrix[i][j] != firstDiagElement)
            {
                return false;
            }
            //check for rest elements
            else if (i != j && matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int matrix1[3][3] = { {9,0,0},{0,9,0},{0,0,9} };

    cout << "\nMatrix1:\n";
    printMatrix(matrix1, 3, 3);

    if (isScalarMatrix(matrix1, 3, 3))
        cout << "\nYES: Matrix is scalar.";
    else
        cout << "\nNo: Matrix is NOT scalar.";

    return 0;
}
