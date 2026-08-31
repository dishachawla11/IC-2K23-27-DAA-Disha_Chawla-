#include <iostream>
using namespace std;

int BinarySearch(int arr2[], int n, int target) {
    int low = 0, high = n-1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr2[mid] == target) {
            return mid;
        }
        else if (arr2[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr2[] = {18, 20, 35, 39, 66, 86, 99};
    int l = sizeof(arr2) / sizeof(arr2[0]);
    int item = 99;

    int result = BinarySearch(arr2, l,item);

    if (result != -1) {
        cout << "Element found at index :" << result << endl;
    }
    else {
        cout << "Element not found in the array" << endl;
    }
    return 0;
}