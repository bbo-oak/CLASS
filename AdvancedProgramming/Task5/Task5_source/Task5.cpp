#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main() {
    ifstream Input;
    string var;

    Input.open("love.txt");

    while(Input >> var){
        if(var == "hate") {
            cout << "love ";
        }
        else 
            cout << var << " ";
    }
    cout << endl;
    
}