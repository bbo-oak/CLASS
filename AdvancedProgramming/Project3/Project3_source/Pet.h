#pragma once

#include <iostream>
#include <string>

using namespace std;

class Pet {
public:
    Pet();
    Pet(const string& newname, const string& newowner, int newrate, int newnights);

    string get_name() const;
    string get_owner() const;
    int get_rate() const;
    int get_nights() const;
    int get_totalfee() const;
    bool get_is_paid() const;

    void nights_minus (int n);
    void set_is_paid(bool b);
    void set_totalfee(int n);

    void operator=(const Pet& p1);
    friend ostream& operator <<(ostream& output, const Pet& p1);


private:
    string name;
    string owner;
    int rate;
    int nights;
    int totalfee;
    bool is_paid;
};