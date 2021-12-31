#include <iostream>

using namespace std;

int* allocArray(int s) {
    int* arr;

    arr = new int[s];

    return arr;
}

void printArray(int* arr) {
    for (int i = 0; i < _msize(arr) / sizeof(arr[0]); i++) {
        cout << i << "번째 원소 : " << arr[i] << endl;
    }
}

void freeArray(int* arr) {
    delete [] arr;
}




int main()

{

    int* arr;

    int size;

 

    cout << "Enter the array size: ";

    cin >> size;

    arr = allocArray (size);

 

    for (int i=0; i<size; i++)

    {

        cout << "Put an array element: ";

        cin >> arr[i];

    }

   

    printArray(arr);

    freeArray(arr);

    return 0;

}