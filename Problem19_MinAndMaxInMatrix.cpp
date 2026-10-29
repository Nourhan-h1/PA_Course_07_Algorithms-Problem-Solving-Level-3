// problem_19_min_and_max_number_in_theMatrix.cpp 

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

int findMinimumMatrixNumber(const int matrix[3][3], short rows, short cols)
{
    int minNumber = matrix[0][0];
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] < minNumber)
            {
                minNumber = matrix[i][j];
            }
        }
    }
    return minNumber;
}


int findMaximumMatrixNumber(const int matrix[3][3], short rows, short cols)
{
    int maxNumber = matrix[0][0];
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] > maxNumber)
            {
                maxNumber = matrix[i][j];
            }
        }
    }
    return maxNumber;
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int matrix[3][3];

    fillRandomMatrix(matrix, 3, 3);
    cout << "Matrix:\n\n";
    printTheRandomMatrix(matrix, 3, 3);


    int minNumber = findMinimumMatrixNumber(matrix, 3, 3);
    int maxNumber = findMaximumMatrixNumber(matrix, 3, 3);

    cout << "\nMinimum number in the matrix is: " << minNumber << "\n";
    cout << "Maximum number in the matrix is: " << maxNumber << "\n";

    return 0;
}
