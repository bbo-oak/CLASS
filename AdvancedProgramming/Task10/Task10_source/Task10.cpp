// 20160394 임효상 Task10 과제 제출입니다.
#include <iostream>

using namespace std;

void fillArray(int arr[], int arr_size) {
    cout << "Put array elements: ";
    
    for(int i = 0; i < arr_size; i++) {
        cin >> arr[i];
    }
}

void printArray(int arr[], int arr_size) {
    cout << "Array elements are ";

    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
}


int main()

{

   int arr[5];

   fillArray (arr, 5);

   printArray (arr, 5);

}