#include<iostream>
using namespace std;
void LinearSearch(int arr[], int len, int key){

    for(int i=0;i<len;i++){
        if(arr[i] == key){
            cout << "Element Found at index : " << i;
            return;
        }
    }
    cout << "Not found";
}
int main() {
    int arr1[] = {20, 22, 80, 90, 29, 7};
    
    // calculating length of array1
    int len = sizeof(arr1)/sizeof(arr1[0]);
    
    //Element to be searched
    int item = 80;
    LinearSearch(arr1, len, item);

    return 0;
} 
