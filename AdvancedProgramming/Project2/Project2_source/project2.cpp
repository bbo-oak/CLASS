#include <iostream>
#include <math.h>

using namespace std;

class NComplex {
public:
    NComplex() {
        num_R = 0;
        num_I = 0;
    }

    NComplex(double a, double b) {
        num_R = a;
        num_I = b;
    }
    double get_num_R() const;
    double get_num_I() const;

    friend const NComplex operator+(const NComplex& n1, const NComplex& n2);
    friend const NComplex operator+(const NComplex& n1, const double& n2);
    friend const NComplex operator+(const double& n1, const NComplex& n2);
    friend const NComplex operator-(const NComplex& n1, const NComplex& n2);
    friend const NComplex operator-(const NComplex& n1, const double& n2);
    friend const NComplex operator-(const double& n1, const NComplex& n2);
    friend const NComplex operator*(const NComplex& n1, const NComplex& n2);
    friend const NComplex operator*(const NComplex& n1, const double& n2);
    friend const NComplex operator*(const double& n1, const NComplex& n2);
    friend const NComplex operator/(const NComplex& n1, const NComplex& n2);
    friend const NComplex operator/(const NComplex& n1, const double& n2);
    friend const NComplex operator/(const double& n1, const NComplex& n2);

    friend ostream& operator <<(ostream& output, const NComplex& v1);




private:
    double num_R, num_I;

};

double NComplex::get_num_R() const{
    return num_R;
}

double NComplex::get_num_I() const{
    return num_I;
}

const NComplex operator+(const NComplex& n1, const NComplex& n2) {
    return NComplex(n1.num_R + n2.num_R, n1.num_I + n2.num_I);
}

const NComplex operator+(const double& n1, const NComplex& n2) {
    return NComplex(n1 + n2.num_R, n2.num_I);
}

const NComplex operator+(const NComplex& n1, const double& n2) {
    return NComplex(n1.num_R + n2, n1.num_I);
}

const NComplex operator-(const NComplex& n1, const NComplex& n2) {
    return NComplex(n1.num_R - n2.num_R, n1.num_I - n2.num_I);
}

const NComplex operator-(const double& n1, const NComplex& n2) {
    return NComplex(n1 - n2.num_R, -n2.num_I);
}

const NComplex operator-(const NComplex& n1, const double& n2) {
    return NComplex(n1.num_R - n2, n1.num_I);
}

const NComplex operator*(const NComplex& n1, const NComplex& n2) {
    double n_R = n1.num_R * n2.num_R - n1.num_I * n2.num_I;
    double n_I = n1.num_R * n2.num_I + n1.num_I * n2.num_R;

    return NComplex(n_R, n_I);
}

const NComplex operator*(const double& n1, const NComplex& n2) {
    return NComplex(n1 * n2.num_R, n1 * n2.num_I);
}

const NComplex operator*(const NComplex& n1, const double& n2) {
    return NComplex(n2 * n1.num_R, n2 * n1.num_I);
}

const NComplex operator/(const NComplex& n1, const NComplex& n2) {
    if((n2.num_R == 0 && (n2.num_I == 0))) {
        cout << "ERROR :: Divide by 0 " << endl;
        exit(0);
    }

    double a = n1.num_R;
    double b = n1.num_I;
    double c = n2.num_R;
    double d = n2.num_I;
    double n_R = (a*c + b*d) / (pow(c,2) + pow(d,2));
    double n_I = (b*c - a*d) / (pow(c,2) + pow(d,2));
    return NComplex(n_R, n_I);
}

const NComplex operator/(const NComplex& n1, const double& n2) {
    if(n2 == 0) {
        cout << "ERROR :: Divide by 0 " << endl;
        exit(0);
    }

    double a = n1.num_R;
    double b = n1.num_I;
    double c = n2;
    double d = 0;
    double n_R = (a*c + b*d) / (pow(c,2) + pow(d,2));
    double n_I = (b*c - a*d) / (pow(c,2) + pow(d,2));
    return NComplex(n_R, n_I);
}

const NComplex operator/(const double& n1, const NComplex& n2) {
    if((n2.num_R == 0 && (n2.num_I == 0))) {
        cout << "ERROR :: Divide by 0 " << endl;
        exit(0);
    }

    double a = n1;
    double b = 0;
    double c = n2.num_R;
    double d = n2.num_I;
    double n_R = (a*c + b*d) / (pow(c,2) + pow(d,2));
    double n_I = (b*c - a*d) / (pow(c,2) + pow(d,2));
    return NComplex(n_R, n_I);
}

ostream& operator <<(ostream& output, const NComplex& n1) {
    output  << n1.num_R << " + " << n1.num_I << "i";

    return output;
}


int main()
{
    NComplex n1 (5.1, 2.2), n2(2.0, 2.0), n3;
    double d1 = 3.0, d2 = 0;

    cout << "n1+n2: " << n1+n2 << endl;
    cout << "n1-n2: " << n1-n2 << endl;
    cout << "n1*n2: " << n1*n2 << endl;
    cout << "n1/n2: " << n1/n2 << endl << endl;

    cout << "n1+d1: " << n1+d1 << endl;
    cout << "n1-d1: " << n1-d1 << endl;
    cout << "n1*d1: " << n1*d1 << endl;
    cout << "n1/d1: " << n1/d1 << endl << endl;

    cout << "d1+n2: " << d1+n2 << endl;
    cout << "d1-n2: " << d1-n2 << endl;
    cout << "d1*n2: " << d1*n2 << endl;
    cout << "d1/n2: " << d1/n2 << endl << endl;


    cout << "d1/n3: " << d1/n3 << endl;
}


