#include <iostream>
using namespace std;

void merge(int arr6[], int low, int mid, int high) {

    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[100];

    while (i <= mid && j <= high) {

        if (arr6[i] < arr6[j]) {
            temp[k] = arr6[i];
            i++;
        }
        else {
            temp[k] = arr6[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp[k] = arr6[i];
        i++;
        k++;
    }

    // Copy remaining elements from right half
    while (j <= high) {
        temp[k] = arr6[j];
        j++;
        k++;
    }

    // Copy sorted elements back to original array
    for (i = low, k = 0; i <= high; i++, k++) {
        arr6[i] = temp[k];
    }
}

void mergeSort(int arr6[], int low, int high) {

    if (low < high) {

        int mid = (low + high) / 2;

        mergeSort(arr6, low, mid);
        mergeSort(arr6, mid + 1, high);

        merge(arr6, low, mid, high);
    }
}

int main() {

    int arr6[] = {66, 54, 99, 2, 90, 22, 11};

    int l = sizeof(arr6) / sizeof(arr6[0]);

    mergeSort(arr6, 0, l - 1);

    cout << "Sorted array is: ";

    for (int i = 0; i < l; i++) {
        cout << arr6[i] << " ";
    }

    return 0;
}