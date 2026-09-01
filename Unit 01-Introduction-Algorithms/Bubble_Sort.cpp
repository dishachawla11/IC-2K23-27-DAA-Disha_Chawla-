#include <iostream>
using namespace std;

int main() {

    int arr1[] = {55, 43, 29, 12, 66, 39, 80};

    int l = sizeof(arr1) / sizeof(arr1[0]);

    for (int i = 0; i < l - 1; i++) {

        for (int j = 0; j < l - i - 1; j++) {

            if (arr1[j] > arr1[j + 1]) {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }
    cout << "The Sorted array is : ";

    for (int i = 0; i < l; i++) {
        cout << arr1[i] << " ";
    }

    return 0;
}