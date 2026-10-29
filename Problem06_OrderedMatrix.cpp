// problem_06_Order Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>

using namespace std;


void fillOrderedMatrix(int matrix[3][3], short rows, short cols) {
    int counter = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = ++counter;
        }
    }
}

void printOrderedMatrix(const int matrix[3][3], short rows, short cols) {

   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            cout << setw(2) << matrix[i][j] << " ";

        }

        cout << "\n";
    }
}

int main() {
    int matrix[3][3];

    fillOrderedMatrix(matrix, 3, 3);

    cout << "The 3x3 ordered matrix is:\n\n";
    printOrderedMatrix(matrix, 3, 3);

    return 0;
}

