#include <iostream>
using namespace std;

int partition(int arr5[], int low, int high) {

    int pivot = arr5[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr5[j] < pivot) {
            i++;

            int temp = arr5[i];
            arr5[i] = arr5[j];
            arr5[j] = temp;
        }
    }

    int temp = arr5[i + 1];
    arr5[i + 1] = arr5[high];
    arr5[high] = temp;

    return i + 1;
}

void quickSort(int arr5[], int low, int high) {

    if (low < high) {

        int pivotIndex = partition(arr5, low, high);

        quickSort(arr5, low, pivotIndex - 1);
        quickSort(arr5, pivotIndex + 1, high);
    }
}

int main() {

    int arr5[] = {33, 4, 99, 8, 1, 2};

    int l = sizeof(arr5) / sizeof(arr5[0]);

    quickSort(arr5, 0, l - 1);

    cout << "Sorted array is: ";

    for (int i = 0; i < l; i++) {
        cout << arr5[i] << " ";
    }

    return 0;
}