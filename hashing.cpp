#include <iostream>
using namespace std;

// Linear approach, Time Complexity: O(Q * N)
int freq(int number, int arr[], int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {  
        if (arr[i] == number) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    int hasharr[100000] = {0};
    for (int i = 0; i < n; i++) {
        hasharr[arr[i]]++;
    }

    int number;
    cout << "Enter the number whose frequency you want to find: ";
    cin >> number;

    cout << "Frequency of " << number << ": " << hasharr[number] << endl;

    return 0;
}

