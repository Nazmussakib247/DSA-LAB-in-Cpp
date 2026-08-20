#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array must contain at least one element.\n";
        return 0;
    }

    int* arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int position;
    cout << "Enter deletion position (1 to " << n << "): ";
    cin >> position;

    if (position < 1 || position > n) {
        cout << "Invalid position.\n";
        delete[] arr;
        return 0;
    }

    for (int i = position - 1; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --n;

    cout << "Array after deletion: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? '\n' : ' ');
    }

    delete[] arr;
    return 0;
}

// Deletes the element at a selected one-based position by shifting later elements left.
// Time complexity: O(n), Space complexity: O(n)
