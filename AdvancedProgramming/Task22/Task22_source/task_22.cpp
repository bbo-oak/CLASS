#include <iostream>

using namespace std;

class A {
public:
    A()
    {
        cout << "Constructor in class A executed" << endl;
    }

    ~A()
    {
        cout << "Destructor in class A executed" << endl;
    }

    int a;
};

class B : public A {
public:
    B()
    {
        cout << "Constructor in class B executed" << endl;
    }

    ~B()
    {
        cout << "Destructor in class B executed" << endl;
    }

    int b;
};

class C : public B {
public:
    C()
    {
        cout << "Constructor in class C executed" << endl;
    }

    ~C()
    {
        cout << "Destructor in class C executed" << endl;
    }

    int c;
};

int main(){
    C* pc = new C;
    delete pc;

}