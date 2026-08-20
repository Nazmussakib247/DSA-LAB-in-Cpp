#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the current number of elements: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid array size.\n";
        return 0;
    }

    int* arr = new int[n + 1];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int position, value;
    cout << "Enter insertion position (1 to " << n + 1 << "): ";
    cin >> position;
    cout << "Enter the value to insert: ";
    cin >> value;

    if (position < 1 || position > n + 1) {
        cout << "Invalid position.\n";
        delete[] arr;
        return 0;
    }

    for (int i = n; i >= position; --i) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = value;
    ++n;

    cout << "Array after insertion: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? '\n' : ' ');
    }

    delete[] arr;
    return 0;
}

// Inserts an element at a selected one-based position by shifting later elements.
// Time complexity: O(n), Space complexity: O(n)
