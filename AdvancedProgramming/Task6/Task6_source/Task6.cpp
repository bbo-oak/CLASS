/* AI융합학부 20160394 임효상 Task6 과제 제출입니다.*/

#include <iostream>

using namespace std;

int main() {
    int a[4][4] = {10, 20, 30, 40, 5, 4 ,3, 99, 55, 100, 42, 100, 0, 105, 2, 11};
    int largenum_first = 0, largenum_second = 0;

    for(int i = 0; i < 16; i++) {
        int target = *(*a + i);
        if(target < largenum_second) 
            continue;
        else if(target > largenum_first)
            largenum_first = target;
        else
            largenum_second = target;
    }

    cout << "The largest number is " << largenum_first << endl;
    cout << "The second-largest number is " << largenum_second << endl;

}