/*
 * basePlusCommission.h
 *
 *  Created on: Sep. 26, 2024
 *      Author: umroot
 */

#ifndef BASEPLUSCOMMISSION_H_
#define BASEPLUSCOMMISSION_H_

#include "commission.h"

#include <string>
#include <iostream>
using namespace std;


class BasePlusCommissionEmployee : public CommissionEmployee {
public:
	BasePlusCommissionEmployee(
		const std::string& firstName,
		const std::string& lastName,
		const std::string& socialSecurityNumber,
		double grossSales=0.0,
		double commissionRate=0.0,
		double baseSalary=0.0
	);
	BasePlusCommissionEmployee(const BasePlusCommissionEmployee&);

	void setBaseSalary(double);
	double getBaseSalary() const;

	//overloading CommissionEmployee::earnings()
	//baseSalary + (commissionRate * grossSales)
	double earnings() const;

	//overloading CommissionEmployee::toString()
	//return extra baseSalary information
	std::string toString() const;


private:
	double baseSalary;

};



#endif /* BASEPLUSCOMMISSION_H_ */
