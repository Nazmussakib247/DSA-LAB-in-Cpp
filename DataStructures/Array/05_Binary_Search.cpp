#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of sorted elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive.\n";
        return 0;
    }

    int* arr = new int[n];
    cout << "Enter " << n << " elements in ascending order: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the value to search: ";
    cin >> target;

    int left = 0, right = n - 1, position = -1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] == target) {
            position = middle + 1;
            break;
        }
        if (arr[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    if (position == -1) {
        cout << target << " was not found.\n";
    } else {
        cout << target << " was found at position " << position << ".\n";
    }

    delete[] arr;
    return 0;
}

// Performs iterative binary search; the input must already be sorted in ascending order.
// Time complexity: O(log n), Space complexity: O(n)
