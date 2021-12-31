#include <iostream>
#include <string>

using namespace std;

class DayOfYear
{
    public:
    string output();
    void adjustDay(int);
    int calc_month_day();
    int month;
    int day;
};

string DayOfYear::output(){
    string s = "";
    
    switch(month) {
        case 1:
            s += "January ";
            break;
        case 2:
            s += "February ";
            break;
        case 3:
            s += "March ";
            break;
        case 4:
            s += "April ";
            break;
        case 5:
            s += "May ";
            break;
        case 6:
            s += "June ";
            break;
        case 7:
            s += "July ";
            break;
        case 8:
            s += "August ";
            break;
        case 9:
            s += "September ";
            break;
        case 10:
            s += "October ";
            break;
        case 11:
            s += "November ";
            break;
        case 12:
            s += "December ";
            break;
        default:
            s += "NULL ";
    }

    s += to_string(day);

    return s;
}

void DayOfYear::adjustDay(int n) {
    int limit = calc_month_day();;
    
    day += n;

    while(!(day < limit && day > 0)) {
        if(day > limit) {
            month++;
            day -= limit;
            if(month >= 13) month = 1;
            limit = calc_month_day();
        }
        else if(day < 0) {
            month--;
            if(month <= 0) month = 12;
            limit = calc_month_day();
            day -= limit;
        }
            
    }

}

int DayOfYear::calc_month_day() {
    int limit;

    switch(month) {
        case 1:
            limit = 31;
            break;
        case 2:
            limit = 28;
            break;
        case 3:
            limit = 31;
            break;
        case 4:
            limit = 30;
            break;
        case 5:
            limit = 31;
            break;
        case 6:
            limit = 30;
            break;
        case 7:
            limit = 31;
            break;
        case 8:
            limit = 31;
            break;
        case 9:
            limit = 30;
            break;
        case 10:
            limit = 31;
            break;
        case 11:
            limit = 30;
            break;
        case 12:
            limit = 31;
            break;
        default:
            limit = 31;
    }

    return limit;
}

int main ()
{

    DayOfYear d1;

    d1.month = 8;

    d1.day = 20;

 

    d1.adjustDay(20);    /* add 20 days to d1 */

    cout << "Adjusted date is: " << d1.output() << endl;

}