#include "hourlyemployee.h"

namespace SavitchEmployees
{
    HourlyEmployee::HourlyEmployee() : Employee(), wageRate(0), hours(0) {

    }

    HourlyEmployee::HourlyEmployee(const string& theName, const string& theNumber, double theWageRate, double theHours)
    : Employee(theName, theNumber), wageRate(theWageRate), hours(theHours) {

    }

    void HourlyEmployee::setRate(double newWageRate) {
        wageRate = newWageRate;
    }

    double HourlyEmployee::getRate() const {
        return wageRate;
    }

    void HourlyEmployee::setHours(double hoursWorked) {
        hours = hoursWorked;
    }

    double HourlyEmployee::getHours() const {
        return hours;
    }

    void HourlyEmployee::printCheck() {
        setNetPay(hours * wageRate);

        cout << "\n_________________________________\n";
        cout << "Pay to the order of " << getName() << endl;
        cout << "the sum of " << getNetPay() << " Dollars\n";
        cout << "\n_________________________________\n";
        cout << "Check Stub: NOT NEGOTIABLE\n";
        cout << "Employee Number: " << getSsn() << endl;
        cout << "Hourly Employee. \nHours worked: " << hours
             << " Rate: " << wageRate << " Pay: " << getNetPay() << endl;
        cout << "\n_________________________________\n";
    }

}