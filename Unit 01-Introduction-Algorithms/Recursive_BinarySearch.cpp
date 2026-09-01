#include <iostream>
using namespace std;

int BinarySearch(int arr3[], int low, int high, int target) {

    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr3[mid] == target) {
        return mid;
    }
    else if (arr3[mid] < target) {
        return BinarySearch(arr3, mid + 1, high, target);
    }
    else {
        return BinarySearch(arr3, low, mid - 1, target);
    }
}

int main() {

    int arr3[] = {8, 16, 20, 31, 39, 44, 60};

    int l = sizeof(arr3) / sizeof(arr3[0]);

    int target = 44;

    int result = BinarySearch(arr3, 0, l - 1, target);

    if (result != -1) {
        cout << "Element found at index: " << result;
    }
    else {
        cout << "Element not found in the array";
    }

    return 0;
}