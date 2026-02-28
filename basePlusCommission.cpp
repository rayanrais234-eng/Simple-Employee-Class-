#include "basePlusCommission.h"
#include "commission.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const std::string& firstName,
    const std::string& lastName,
    const std::string& socialSecurityNumber,
    double grossSales,
    double commissionRate,
    double baseSalary
): CommissionEmployee(firstName, lastName, socialSecurityNumber, grossSales, commissionRate), baseSalary(baseSalary)
{

}
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const BasePlusCommissionEmployee& employee)
: CommissionEmployee(employee), baseSalary(employee.baseSalary)
{

}

void BasePlusCommissionEmployee::setBaseSalary(double salary){
    if(salary<0.0)
        throw invalid_argument("Base salary must be >= 0.0");
    baseSalary = salary;
}
double BasePlusCommissionEmployee::getBaseSalary() const{
    return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const{
    return baseSalary + (getCommissionRate() * getGrossSales());
}

std::string BasePlusCommissionEmployee::toString() const{
    ostringstream output;
    output << fixed << setprecision(2);
    output << "base-salaried commission employee: " << getFirstName()
           << " " << getLastName()
           << "\nsocial security number: " << getSocialSecurityNumber()
           << "\ngross sales: " << getGrossSales()
           << "\ncommission rate: " << getCommissionRate()
           << "\nbase salary: " << getBaseSalary()
           << "\nearnings: " << earnings();
    return output.str();
}
