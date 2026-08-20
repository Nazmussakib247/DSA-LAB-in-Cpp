#include <iostream>
using namespace std;

int main() {
    int n, rotations;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive.\n";
        return 0;
    }

    int* arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the number of left rotations: ";
    cin >> rotations;
    rotations %= n;
    if (rotations < 0) {
        rotations += n;
    }

    for (int count = 0; count < rotations; ++count) {
        int first = arr[0];
        for (int i = 0; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = first;
    }

    cout << "Array after left rotation: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? '\n' : ' ');
    }

    delete[] arr;
    return 0;
}

// Rotates the array left by k positions using repeated one-position rotations.
// Time complexity: O(nk), Space complexity: O(n)
