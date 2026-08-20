#include <iostream>
using namespace std;

int main() {
    int n;
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

    int minimum = arr[0];
    int maximum = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }

    cout << "Minimum value: " << minimum << '\n';
    cout << "Maximum value: " << maximum << '\n';

    delete[] arr;
    return 0;
}

// Finds both extreme values in one pass through the array.
// Time complexity: O(n), Space complexity: O(n)
