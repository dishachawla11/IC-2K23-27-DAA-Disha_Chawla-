#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;

// Linear Search
int linearSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(const vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
// Bubble Sort
void bubbleSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= right)
        temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[left + k] = temp[k];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Automated Sorting Comparison
void compareSortingAlgorithms(const vector<int>& original) {

    const int repetitions = 10000;

    ofstream file("results.csv", ios::app);

    // Check whether CSV file is empty
    ifstream check("results.csv");
    bool writeHeader = !check.good() ||
        check.peek() == ifstream::traits_type::eof();
    check.close();

    if (writeHeader) {
        file << "Algorithm,Input Size,Execution Time (nanoseconds)\n";
    }

    // Function to calculate average execution time
    auto measure = [&](auto sortFunction) {

        long long totalTime = 0;
        volatile int sink = 0;

        for (int i = 0; i < repetitions; i++) {

            vector<int> arr = original;

            auto start = chrono::high_resolution_clock::now();

            sortFunction(arr);

            auto end = chrono::high_resolution_clock::now();

            totalTime += chrono::duration_cast<
                chrono::nanoseconds>(end - start).count();

            sink = arr[0];
        }

        return (double)totalTime / repetitions;
    };

    // Bubble Sort
    double bubble = measure([](vector<int>& a) {
        bubbleSort(a);
    });

    cout << "\nBubble Sort: " << bubble << " ns";
    file << "Bubble Sort," << original.size() << "," << bubble << "\n";

    // Insertion Sort
    double insertion = measure([](vector<int>& a) {
        insertionSort(a);
    });

    cout << "\nInsertion Sort: " << insertion << " ns";
    file << "Insertion Sort," << original.size() << "," << insertion << "\n";

    // Selection Sort
    double selection = measure([](vector<int>& a) {
        selectionSort(a);
    });

    cout << "\nSelection Sort: " << selection << " ns";
    file << "Selection Sort," << original.size() << "," << selection << "\n";

    // Merge Sort
    double merge = measure([](vector<int>& a) {
        mergeSort(a, 0, a.size() - 1);
    });

    cout << "\nMerge Sort: " << merge << " ns";
    file << "Merge Sort," << original.size() << "," << merge << "\n";

    // Quick Sort
    double quick = measure([](vector<int>& a) {
        quickSort(a, 0, a.size() - 1);
    });

    cout << "\nQuick Sort: " << quick << " ns";
    file << "Quick Sort," << original.size() << "," << quick << "\n";

    file.close();

    cout << "\n\nAverage execution times saved in results.csv\n";
}



int main() {

    int choice, n, key;
    string algorithmName;

    cout << "\n===== ALGORITHM PERFORMANCE ANALYZER =====\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Insertion Sort\n";
    cout << "5. Selection Sort\n";
    cout << "6. Merge Sort\n";
    cout << "7. Quick Sort\n";
    cout << "8. Exit\n";
    cout << "9. Compare All Sorting Algorithms\n";

    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 8) {
        cout << "Exiting program...";
        return 0;
    }

    if (choice < 1 || choice > 9) {
        cout << "Invalid choice!";
        return 0;
    }

    cout << "\nEnter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of elements!";
        return 0;
    }

    vector<int> arr(n);

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = -1;
    if (choice == 9) {

    compareSortingAlgorithms(arr);

    return 0;
}

    if (choice == 2) {
        sort(arr.begin(), arr.end());

        cout << "Enter element to search: ";
        cin >> key;
    }

    if (choice == 1) {
        cout << "Enter element to search: ";
        cin >> key;
    }

    auto start = chrono::high_resolution_clock::now();

    switch (choice) {

        case 1:
            algorithmName = "Linear Search";
            result = linearSearch(arr, key);
            break;

        case 2:
            algorithmName = "Binary Search";
            result = binarySearch(arr, key);
            break;

        case 3:
            algorithmName = "Bubble Sort";
            bubbleSort(arr);
            break;

        case 4:
            algorithmName = "Insertion Sort";
            insertionSort(arr);
            break;

        case 5:
            algorithmName = "Selection Sort";
            selectionSort(arr);
            break;

        case 6:
            algorithmName = "Merge Sort";
            mergeSort(arr, 0, n - 1);
            break;

        case 7:
            algorithmName = "Quick Sort";
            quickSort(arr, 0, n - 1);
            break;
    }

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(
        end - start
    ).count();

    cout << "\nAlgorithm: " << algorithmName;
    cout << "\nExecution Time: " << duration << " nanoseconds";

    if (choice == 1 || choice == 2) {
        cout << "\nSearch Result: ";

        if (result != -1)
            cout << "Element found at index " << result;
        else
            cout << "Element not found";
    }

    if (choice >= 3 && choice <= 7) {
        cout << "\nSorted Array: ";

        for (int x : arr) {
            cout << x << " ";
        }
    }

    ifstream check("results.csv");

    bool writeHeader = !check.good() ||
        check.peek() == ifstream::traits_type::eof();

    check.close();

    ofstream file("results.csv", ios::app);

    if (writeHeader) {
       file << "Algorithm,Input Size,Execution Time (nanoseconds)\n";
    }

    file << algorithmName << "," << n << "," << duration << "\n";

    file.close();

    cout << "\n\nResults saved in results.csv";

    return 0;
}
