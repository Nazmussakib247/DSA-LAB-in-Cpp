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

    int** first = new int*[rows];
    int** second = new int*[rows];
    int** sum = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        first[i] = new int[columns];
        second[i] = new int[columns];
        sum[i] = new int[columns];
    }

    cout << "Enter the first matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> first[i][j];
        }
    }

    cout << "Enter the second matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> second[i][j];
            sum[i][j] = first[i][j] + second[i][j];
        }
    }

    cout << "Sum matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << sum[i][j] << (j == columns - 1 ? '\n' : ' ');
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] first[i];
        delete[] second[i];
        delete[] sum[i];
    }
    delete[] first;
    delete[] second;
    delete[] sum;
    return 0;
}

// Adds two matrices with identical dimensions element by element.
// Time complexity: O(rows * columns), Space complexity: O(rows * columns)
