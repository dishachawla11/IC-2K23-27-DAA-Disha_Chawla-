#include <iostream>
using namespace std;

int main() {
    int arr2[] = {94, 88, 35, 90, 12,45};

    int l = sizeof(arr2) / sizeof(arr2[0]);

    // Selection Sort
    for (int i = 0; i < l - 1; i++) {

        int minIndex = i;

        for (int j = i + 1; j < l; j++) {

            if (arr2[j] < arr2[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr2[i];
        arr2[i] = arr2[minIndex];
        arr2[minIndex] = temp;
    }
    cout << "The Sorted array is: ";

    for (int i = 0; i < l; i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}