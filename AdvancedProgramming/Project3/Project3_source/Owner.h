#pragma once

#include "Pet.h"
#include <vector>

using namespace std;

class Owner {
public:
    Owner();
    Owner(const string& newname, int newbalance);

    string get_name() const;
    int get_balance() const;
    int get_numpet() const;

    void set_num_pet(int n);
    void set_legacy(bool b);
    int balance_minus(int n);

    friend ostream& operator <<(ostream& output, const Owner& o1);

private:
    string name;
    int balance;
    int num_pet;
    bool legacy;
};