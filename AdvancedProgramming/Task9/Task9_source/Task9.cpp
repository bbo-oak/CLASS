#include <iostream>

using namespace std;


void sort_three (int& a, int& b, int& c)
{
    int tmp = 0;
    if(b > a && b > c) {
        tmp = a;
        a = b;
        b = tmp;
    }
    else if(c > a && c > b) {
        tmp = a;
        a = c;
        c = tmp;
    }

    if(b < c) {
        tmp = c;
        c = b;
        b = tmp;
    }
}

 

int main ()

{

   int i1 = 100, i2 = 90, i3 = 500;

   sort_three (i1, i2, i3);

   cout << "Three numbers are: "

        << i1 << " , " << i2 << " , " << i3 << endl;

}