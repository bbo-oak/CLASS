#include <iostream>

using namespace std;

int iAdd(int a, int b) {
    return a+b;
}

int iSub(int a, int b) {
    return a-b;
}

int iMul(int a, int b) {
    return a*b;
}

int iDiv(int a, int b) {
    return a/b;
}

int main()

{

   int a = 20, b = 10;

   cout << "Add: " << iAdd(a,b) << endl;

   cout << "Sub: " << iSub(a,b) << endl;

   cout << "Mul: " << iMul(a,b) << endl;

   cout << "Div: " << iDiv(a,b) << endl;

 

   return 0;

}

