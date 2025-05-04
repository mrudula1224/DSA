#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int largestelement(int arr[], int n) {
    int largest = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

vector<int> minAnd2ndMin(vector<int>& arr) {
    int smallest = INT_MAX;
    int second_smallest = INT_MAX;
    int n = arr.size();
    vector<int> ans(2);
    
    if (n < 2) {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != smallest && arr[i] < second_smallest) {
            second_smallest = arr[i];
        }
    }

    if (second_smallest == INT_MAX) {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }

    ans[0] = smallest;
    ans[1] = second_smallest;
    return ans;
}

bool arraySortedOrNot(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int removedupli(int arr[], int n) {
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);
    }

    int index = 0;
    set<int>::iterator it;
    for (it = st.begin(); it != st.end(); ++it) {
        arr[index] = *it;
        index += 1;
    }

    return index;
}

int removeDuplicates(vector<int>& arr) {
    int i = 0;
    int n = arr.size();
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            arr[i + 1] = arr[j];
            i = i + 1;
        }
    }
    return i + 1;
}

int main(int argc, char const* argv[]) {
    int arr[] = {1, 2, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The largest element in the array is: " << largestelement(arr, n) << endl;

    vector<int> vec(arr, arr + n);
    vector<int> result = minAnd2ndMin(vec);

    cout << "The smallest element is: " << result[0] << endl;
    cout << "The second smallest element is: " << result[1] << endl;

    int new_n = removedupli(arr, n);
    cout << "Array after removing duplicates using set: ";
    for (int i = 0; i < new_n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(vec.begin(), vec.end());
    int unique_count = removeDuplicates(vec);
    cout << "Array after removing duplicates (sorted optimal method): ";
    for (int i = 0; i < unique_count; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    cout << "Is the array sorted? " << (arraySortedOrNot(vec) ? "Yes" : "No") << endl;

    return 0;
}




