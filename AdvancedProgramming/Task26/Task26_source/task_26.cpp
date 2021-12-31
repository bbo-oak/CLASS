#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Quad{
public:
    Quad(T a1, T a2, T a3, T a4);

    template<typename U>
    friend ostream& operator<<(ostream& output, const Quad<U>& q1);


private:
    T arg1; T arg2; T arg3; T arg4;
};

template<typename T>
Quad<T>::Quad(T a1, T a2, T a3, T a4) {
    arg1 = a1;
    arg2 = a2;
    arg3 = a3;
    arg4 = a4;
}

template<typename T>
ostream& operator<<(ostream& output, const Quad<T>& q1) {
    output << "=Elements are : <" << q1.arg1 << ", " << q1.arg2 << ", " << q1.arg3 << ", " << q1.arg4 << ">" << endl;

    return output;
}

int main ()
{

  Quad<int> qi (5,6,7,8);

  Quad<string> qs ("hello", "C++", "programming", "language");

  Quad<double> qd (1.1, 2.2, 3.3, 4.4);

 

  cout << qi << endl;

  cout << qs << endl;

  cout << qd << endl;

}