#include "Owner.h"

Owner::Owner() : name("NOPE"), balance(0), num_pet(0), legacy(false) {

}

Owner::Owner(const string& newname, int newbalance) : name(newname), balance(newbalance), num_pet(0), legacy(false) {

}

string Owner::get_name() const {
    return name;
}

int Owner::get_balance() const {
    return balance;
}

int Owner::get_numpet() const {
    return num_pet;
}

int Owner::balance_minus(int n) {
    if(balance - n <= 0) {
        return -1;
    }
    else {
        balance -= n;
        return balance;
    }
}

void Owner::set_num_pet(int n) {
    num_pet += n;
}

void Owner::set_legacy(bool b) {
    legacy = b;
}

ostream& operator <<(ostream& output, const Owner& o1) {

    output << "Owner {name: " << o1.name << ", balance: " << o1.balance 
            << ", numPetsCheckin: " << o1.num_pet << "}" << endl;
    /*
    if(!(o1.legacy)) {
        output << "Owner {name: " << o1.name << ", balance: " << o1.balance 
            << ", numPetsCheckin: " << o1.num_pet << "}" << endl;
    }
    */
    

    return output;
}