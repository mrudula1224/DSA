/*
    ============================================
    Title: Basic Recursion Practice (Striver A2Z)
    Description: Common recursion problems for 
                 beginners such as:
                 - Printing numbers
                 - Reversing arrays
                 - Printing names
                 - Calculating sum
    Source: Striver's A2Z DSA Sheet
    ============================================
*/

#include <iostream>
using namespace std;

// Print numbers from 1 to 20 using recursion
void printOneToTwenty(int n) {
    if (n <= 20) {
        cout << n << " ";
        printOneToTwenty(n + 1);
    }
}

// Print numbers from 0 to 2 (3 values) using recursion
int counter = 0;
void printZeroToTwo() {
    if (counter == 3) return;
    cout << counter << endl;
    counter++;
    printZeroToTwo();
}

// Print a name 'n' times using recursion
void printNameNTimes(int i, int n) {
    if (i > n) return;
    cout << "Murdula" << endl;
    printNameNTimes(i + 1, n);
}

// Print numbers from 'i' to 1 (reverse order)
void printReverse(int i) {
    if (i < 1) return;
    cout << i << endl;
    printReverse(i - 1);
}

// Print the sum of first 'i' numbers
void printSumOfN(int i, int currentSum) {
    if (i < 0) {
        cout << currentSum;
        return;
    }
    printSumOfN(i - 1, currentSum + i);
}

// Reverse an array using two-pointer recursion
void reverseArrayTwoPointer(int arr[], int left, int right) {
    if (left >= right) return;
    swap(arr[left], arr[right]);
    reverseArrayTwoPointer(arr, left + 1, right - 1);
}

// Reverse an array using single-pointer recursion
void reverseArraySinglePointer(int i, int arr[], int n) {
    if (i >= n / 2) return;
    swap(arr[i], arr[n - i - 1]);
    reverseArraySinglePointer(i + 1, arr, n);
}

int main() {
    // Uncomment any function below to test

    // printOneToTwenty(1);
    // printZeroToTwo();
    // printNameNTimes(1, 3);
    // printReverse(3);
    // printSumOfN(5, 0);

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // reverseArrayTwoPointer(arr, 0, n - 1);
    reverseArraySinglePointer(0, arr, n);

    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

