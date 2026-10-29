// problem_10_Sum Of Matrix Elements.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int matrix[3][3];

    fillRandomMatrix(matrix, 3, 3);
    cout << "Matrix:\n\n";
    printTheRandomMatrix(matrix, 3, 3);

	cout << "\nSum of matrix elements is: " << sumOfMatrixElements(matrix, 3, 3) << "\n";
    return 0;
}