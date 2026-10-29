// Problem 07 - Transpose Matrix
//
// Builds an ordered 3x3 matrix (1..9) and prints its transpose, where
// rows become columns: transposed[i][j] = matrix[j][i].
//
// Example Output:
//   The following is a 3x3 ordered matrix:
//
//     1   2   3
//     4   5   6
//     7   8   9
//
//   The following is the transposed matrix:
//
//     1   4   7
//     2   5   8
//     3   6   9

// problem_07_Transpost Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>

using namespace std;

void FillOrderedMatrix(int matrix[3][3], short rows, short cols) {
    int counter = 0;
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            matrix[i][j] = ++counter;
        }
    }
}

void PrintMatrix(const int matrix[3][3], short rows, short cols) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void TransposeMatrix(const int matrix[3][3], int matrixTransposed[3][3], short rows, short cols) {
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            matrixTransposed[i][j] = matrix[j][i];
        }
    }
}

int main() {
    int matrix[3][3];
    int matrixTransposed[3][3];

    FillOrderedMatrix(matrix, 3, 3);
    cout << "\nThe following is a 3x3 ordered matrix:\n\n";
    PrintMatrix(matrix, 3, 3);

    TransposeMatrix(matrix, matrixTransposed, 3, 3);
    cout << "\n\nThe following is the transposed matrix:\n\n";
    PrintMatrix(matrixTransposed, 3, 3);

    return 0;
}
