#include <iostream>

using namespace std;

struct CDAccountV1
{
    double balance;
    double interestRate;
    int term;
};

void swap(CDAccountV1 &v1, CDAccountV1 &v2);

int main()

{

    struct CDAccountV1 v1 = {10.0, 0.01, 60};

    struct CDAccountV1 v2 = {50.0, 0.02, 30};

   

    swap(v1, v2);

    cout << "balance:"  << v1.balance

            << " interest: " << v1.interestRate

            << " terms: " << v1.term << endl;

 
     cout << "balance:"  << v2.balance

            << " interest: " << v2.interestRate

            << " terms: " << v2.term << endl;


}

void swap(CDAccountV1 &v1, CDAccountV1 &v2) {
    double tmp_d;
    int tmp_i;

    tmp_d = v1.balance;
    v1.balance = v2.balance;
    v2.balance = tmp_d;

    tmp_d = v1.interestRate;
    v1.interestRate = v2.interestRate;
    v2.interestRate = tmp_d;

    tmp_i = v1.term;
    v1.term = v2.term;
    v2.term = tmp_i;
}