// Problem 18 - Intersected Numbers in Matrices
//
// Prints the numbers that exist in both random matrices (1-10). Each number is
// printed once even if it repeats, because isNumberInArray checks the result
// array before a number is added.

// problem_18_find_intersected_number_in_matrices.cpp 

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

bool isNumberInMatrix(const int matrix[3][3], short rows, short cols, int number)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] == number)
            {
                return true;
            }
        }
    }
    return false;
}

bool isNumberInArray(const int arr[], short size, int number)
{
    for (short i = 0; i < size; i++)
    {
        if (arr[i] == number)
        {
            return true;
        }
    }
    return false;
}

short getIntersectedNumbers(const int matrix1[3][3], const int matrix2[3][3], short rows, short cols, int resultArray[])
{
    short intersectionCount = 0;

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            int currentNumber = matrix1[i][j];

            if (isNumberInMatrix(matrix2, rows, cols, currentNumber) && !isNumberInArray(resultArray, intersectionCount, currentNumber))
            {
                resultArray[intersectionCount] = currentNumber;
                intersectionCount++;
            }
        }
    }
    return intersectionCount;
}

void printIntersectedNumbers(const int matrix1[3][3], const int matrix2[3][3], short rows, short cols)
{
    int arrayResult[9];
    int size = getIntersectedNumbers(matrix1, matrix2, rows, cols, arrayResult);

    if (size == 0)
    {
        cout << "\nNo intersected numbers found in both matrices.\n";
    }
    else
    {
        cout << "\nIntersected numbers in both matrices:\n";
        for (short i = 0; i < size; i++)
        {
            cout << setw(3) << arrayResult[i] << "    ";
        }
        cout << "\n";
    }
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

    printIntersectedNumbers(matrix1, matrix2, 3, 3);

    return 0;
}

