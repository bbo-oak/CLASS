// 20160394 임효상 Task11 과제 제출입니다.
#include <iostream>
#include <string>

using namespace std;

int add(int i1, int i2) {
    return i1 + i2;
}

double add(double d1, double d2) {
    return d1 + d2;
}

string add(string s1, string s2) {
    return s1 + s2;
}

int main(void)

{

   int i1 = 10, i2 = 30;

   double d1 = 0.5, d2 = 3.5;

   string s1 = "Hello", s2 = "World";

    cout.setf(ios::showpoint);
    cout.precision(2);

   cout << add (i1, i2) << ", "

        << add (d1, d2) << ", "

        << add (s1, s2) << endl;

}