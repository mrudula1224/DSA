#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Function to rotate an array by one place to the left
void leftrotateby1place(int arr[], int n)
{
    int temp = arr[0];
    for(int i = 1; i < n; i++) // Time Complexity = O(N), Extra Space = O(1)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

// Function to rotate an array by d places to the left
void rotateArr(vector<int>& arr, int d)
{
    int n = arr.size();
    d = d % n;
    int temp[d];
    
    for(int i = 0; i < d; i++){
        temp[i] = arr[i];
    }
    
    for(int i = d; i < n; i++){
        arr[i - d] = arr[i];
    }
    
    int j = 0;
    for(int i = n - d; i < n; i++){
        arr[i] = temp[j];
        j += 1;
    }
}

// Class to move all zeroes to end of array while maintaining order
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int j = -1;

        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                j = i;
                break;
            }
        }

        if(j == -1) return;

        for(int i = j + 1; i < n; i++){
            if(arr[i] != 0){
                swap(arr[i], arr[j]);
                j += 1;
            }
        }
    }
};

// Class to search an element in array
class Solution2 {
public:
    int search(vector<int>& arr, int x) {
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[i] == x){
                return i;
            }
        }
        return -1;
    }
};

// Class to find union of two arrays using set
class Solution3 {
public:
    int findUnion(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();
        set<int> s;

        for(int i = 0; i < n1; i++){
            s.insert(a[i]);
        }
        for(int i = 0; i < n2; i++){
            s.insert(b[i]);
        }

        return s.size();
    }
};

int main()
{
    // 1. leftrotateby1place
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    leftrotateby1place(arr, n);
    cout << "Array after 1 left rotation: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    // 2. rotateArr
    int arr1[] = {10, 20, 30, 40, 50, 60};
    vector<int> v1(arr1, arr1 + 6);
    rotateArr(v1, 2);
    cout << "Array after rotating by 2 places: ";
    for(int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
    cout << endl;

    // 3. moveZeroes
    int arr2[] = {0, 1, 0, 3, 12};
    vector<int> v2(arr2, arr2 + 5);
    Solution s;
    s.moveZeroes(v2);
    cout << "Array after moving zeroes to end: ";
    for(int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
    cout << endl;

    // 4. search
    int arr3[] = {5, 8, 10, 15};
    vector<int> v3(arr3, arr3 + 4);
    Solution2 s2;
    int idx = s2.search(v3, 10);
    cout << "Index of 10 in array: " << idx << endl;

    // 5. findUnion
    int arrA[] = {1, 2, 4, 5};
    int arrB[] = {2, 3, 5, 6};
    vector<int> a(arrA, arrA + 4);
    vector<int> b(arrB, arrB + 4);
    Solution3 s3;
    int unionCount = s3.findUnion(a, b);
    cout << "Count of elements in union: " << unionCount << endl;

    return 0;
}
