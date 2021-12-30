#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int main() {
    int score_dmath = 0, score_prog = 0, score_data = 0;
    double score_Avg = 0.0;
    string grade = "";

    cout << "Put the discrete math score: ";
    cin >> score_dmath;
    cin.ignore();

    cout << "Put the programming language score: ";
    cin >> score_prog;
    cin.ignore();

    cout << "Put the data structure score: ";
    cin >> score_data;
    cin.ignore();

    score_Avg = (score_dmath + score_prog + score_data) / 3.0;
    score_Avg = round(score_Avg * 100) / 100;

    if(score_Avg > 95) {
        grade = "A+";
    }
    else if (score_Avg > 90) {
        grade = "A0";
    }
    else if (score_Avg > 85) {
        grade = "B+";
    }
    else if (score_Avg > 80) {
        grade = "B0";
    }
    else if (score_Avg > 75) {
        grade = "C+";
    }
    else if (score_Avg > 70) {
        grade = "C0";
    }
    else{
        grade = "F";
    }

    cout << "The average score is " << score_Avg << " and the grade is " << grade << endl;;

}