#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include "Owner.h"
#include "Pet.h"

using namespace std;

#define MAXSIZE 100

class Hotel {
public:
    Hotel();
    ~Hotel();

    void insert_Pet(Pet p);
    void insert_Owner(Owner o);
    void timemachine(int d);
    void showpets();
    void showowners();
    void getbalance();

    Owner* find_Owner(string ownername);

private:
    Pet* list_pet[MAXSIZE];
    Owner* list_owner[MAXSIZE];
    int balance;
    int dayspassed;
    int point_list_pet;
    int point_list_owner;
};

Hotel::Hotel() : balance(0), dayspassed(0), point_list_owner(0), point_list_pet(0){
    for (int i = 0; i < MAXSIZE; i++) {
        list_pet[i] = NULL;
    }
    for (int i = 0; i < MAXSIZE; i++) {
        list_owner[i] = NULL;
    }
}

Hotel::~Hotel() {
    for (int i = 0; i < MAXSIZE; i++) {
        delete list_pet[i];
    }

    for (int i = 0; i < MAXSIZE; i++) {
        delete list_owner[i];
    }
}

void Hotel::insert_Pet(Pet p) {

    for(int i = 0; i < point_list_pet; i++) {
        if(list_pet[i] != NULL) {
            if(list_pet[i]->get_name() == p.get_name()) {
                return;
            }
        }
    }

    Owner* o = find_Owner(p.get_owner());
    Pet* tmp_pet = new Pet();
    *tmp_pet = p;

    list_pet[point_list_pet] = tmp_pet;
    point_list_pet++;
    o->set_num_pet(1);
    o->set_legacy(false);
}

void Hotel::insert_Owner(Owner o) {

    for(int i = 0; i < point_list_owner; i++) {
        if(list_owner[i] != NULL) {
            if(list_owner[i]->get_name() == o.get_name()) {
                return;
            }
        }
    }

    Owner* tmp_owner = new Owner();
    *tmp_owner = o;

    list_owner[point_list_owner] = tmp_owner;
    point_list_owner++;
}

void Hotel::timemachine(int d) {
    
    cout << d << " days passed." << endl;
    
    dayspassed += d;
    

    for (int i = 0; i < point_list_pet + 1; i++) {
        if(list_pet[i] != NULL) {
            
            list_pet[i]->nights_minus(d);

            if((list_pet[i]->get_nights() == 0) && (list_pet[i]->get_is_paid())) {
                Owner* o = find_Owner(list_pet[i]->get_owner());
                int pay = list_pet[i]->get_totalfee();

                if(o->balance_minus(pay) != -1) {
                    balance += pay;

                    o->set_num_pet(-1);
                    if(o->get_numpet() == 0) 
                        o->set_legacy(true);

                    delete list_pet[i];
                    list_pet[i] = NULL;
                }
                else {
                    list_pet[i]->set_is_paid(false);
                }
            }
        }
    }
}

void Hotel::showpets() {
    for (int i = 0; i < point_list_pet; i++) {
        if(list_pet[i] != NULL) {
            cout << *list_pet[i] ;
        }
    }
}

void Hotel::showowners() {
    for (int i = 0; i < point_list_owner; i++) {
        if(list_owner[i] != NULL) {
            cout << *list_owner[i] ;
        }
    }
}

void Hotel::getbalance() {
    cout << "Working days: " << dayspassed << ", Balance: " << balance << endl << endl;
}

Owner* Hotel::find_Owner(string ownername) {
    for (int i = 0; i < point_list_owner + 1; i++) {
        if(list_owner[i] != NULL) {
            if(list_owner[i]->get_name() == ownername) {
                return list_owner[i];
            }
        }
    }

    cout << "## There is no such name : " << ownername << endl;
    return NULL;
}



int main() {
    int a;
    string cmd;
    Hotel trivago = Hotel();
    ifstream fin;

    fin.open("input.txt");

    while(!fin.eof()) {
        fin >> cmd;

        if(fin.eof())
            break; 

        if(cmd == "register") {
            string x, y;
            fin >> x >> y;

            //cout << cmd << " " << x  << " "<< y << endl << endl;

            Owner o = Owner(x, atoi(y.c_str()));
            o.set_legacy(false);
            trivago.insert_Owner(o);
        }
        else if(cmd == "checkin") {
            string x, y, z, w;
            bool paid;
            fin >> x >> y >> z >> w;

            //cout << cmd << " " << x << " " << y << " " << z << endl << endl;

            Pet p = Pet(y, x, atoi(z.c_str()), atoi(w.c_str()));
            p.set_totalfee(atoi(z.c_str()) * atoi(w.c_str()));
            trivago.insert_Pet(p);
        }
        else if(cmd == "showpets") {

            //cout << cmd << endl << endl;
            trivago.showpets();
        }
        else if(cmd == "showowners") {

            //cout << cmd << endl << endl;
            trivago.showowners();
        }
        else if(cmd == "getbalance") {

            //cout << cmd << endl << endl;
            trivago.getbalance();
        }
        else if(cmd == "pass") {
            string x;
            fin >> x;

            //cout << cmd << " " << x << endl << endl;

            trivago.timemachine(atoi(x.c_str()));
        }
    }
    
}