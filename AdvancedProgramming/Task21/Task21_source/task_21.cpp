#include "hourlyemployee.h"

using namespace std;
using namespace SavitchEmployees;

class UnivHourlyEmployee : public HourlyEmployee {
public:
    UnivHourlyEmployee();
    UnivHourlyEmployee(const string& theName, const string& theSsn,
                    const string& theUname, double theWageRate, double theHours);

    void printInfo();

private:
    string univName;
};

UnivHourlyEmployee::UnivHourlyEmployee() : HourlyEmployee(), univName("No"){

}

UnivHourlyEmployee::UnivHourlyEmployee(const string& theName, const string& theSsn,
                    const string& theUname, double theWageRate, double theHours)
                    : HourlyEmployee(theName, theSsn, theWageRate, theHours), univName(theUname) {

}

void UnivHourlyEmployee::printInfo() {
    
    cout << "Employee name:" << getName() << ", Affliation:" << univName << endl;

    printCheck();
}







int main()

{

    UnivHourlyEmployee john("JohnDoe", "123456", "SSU", 10, 40);

    john.printInfo();

}