#include "Pet.h"

Pet::Pet() : name("NOPE"), owner("NOPE"), rate(0), nights(0), is_paid(false){

}

Pet::Pet(const string& newname, const string& newowner, int newrate, int newnights) 
    : name(newname), owner(newowner), rate(newrate), nights(newnights), is_paid(true){

}

string Pet::get_name() const {
    return name;
}

string Pet::get_owner() const {
    return owner;
}

int Pet::get_rate() const {
    return rate;
}

int Pet::get_nights() const {
    return nights;
}

bool Pet::get_is_paid() const {
    return is_paid;
}

int Pet::get_totalfee() const {
    return totalfee;
}

void Pet::nights_minus(int n) {
    nights -= n;

    if(nights < 0) nights = 0;
}

void Pet::set_is_paid(bool b) {
    is_paid = b;
}

void Pet::set_totalfee(int n) {
    totalfee = n;
}

void Pet::operator=(const Pet& p1) {
    name = p1.name;
    owner = p1.owner;
    rate = p1.rate;
    nights = p1.nights;
    totalfee = p1.totalfee;
    is_paid = p1.is_paid;
}

ostream& operator <<(ostream& output, const Pet& p1) {
    output << "Pet {name: " << p1.name << ", owner: " << p1.owner << ", rate: " 
         << p1.rate << ", remainNights: " << p1.nights << "}" << endl;

    return output;
}