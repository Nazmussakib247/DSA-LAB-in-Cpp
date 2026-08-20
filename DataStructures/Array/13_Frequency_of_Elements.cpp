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
    bool* counted = new bool[n]{};

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Element frequencies:\n";
    for (int i = 0; i < n; ++i) {
        if (counted[i]) {
            continue;
        }

        int frequency = 1;
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) {
                ++frequency;
                counted[j] = true;
            }
        }
        cout << arr[i] << " occurs " << frequency << " time(s).\n";
    }

    delete[] arr;
    delete[] counted;
    return 0;
}

// Counts the number of occurrences of every distinct element using nested loops.
// Time complexity: O(n^2), Space complexity: O(n)
