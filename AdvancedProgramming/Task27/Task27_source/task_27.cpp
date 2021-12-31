#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, string> container;
    string id, name;

    while(1) {
        cout << "Enter the ID number: ";
        cin >> id;

        if(id == "0") {
            break;
        }

        cout << "Enter the student name: ";
        cin >> name;

        container.insert(make_pair(id,name));
    }

    cout << "Enter the searching ID number: ";
    cin >> id;

    cout << "The student name is " << container.find(id)->second << endl;

}