#include <iostream>
using namespace std;

int main() {
    int rows, columns;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> columns;

    if (rows <= 0 || columns <= 0) {
        cout << "Matrix dimensions must be positive.\n";
        return 0;
    }

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[columns];
    }

    cout << "Enter the matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Transpose matrix:\n";
    for (int column = 0; column < columns; ++column) {
        for (int row = 0; row < rows; ++row) {
            cout << matrix[row][column]
                 << (row == rows - 1 ? '\n' : ' ');
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}

// Prints the transpose by exchanging the row and column traversal order.
// Time complexity: O(rows * columns), Space complexity: O(rows * columns)
