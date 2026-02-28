/*
 * testDriver.cpp
 *
 *  Created on: Sep. 26, 2024
 *      Author: umroot
 */

#include "basePlusCommission.h"
#include "commission.h"
#include <iostream>
using namespace std;

void testBaseObject(){
	CommissionEmployee comMember //base class
	("hkl","yui","4567890234",350000, 0.35);
	cout << comMember.toString() << endl;
}

void testDerivedObject(){

	BasePlusCommissionEmployee basePlusMember //derived class
	 ("abc","def","0987654321",250000, 0.15, 5000);

	cout << basePlusMember.toString() << endl;

}

int main(){
	CommissionEmployee comMember
	("hkl","yui","4567890234",350000, 0.35);
	BasePlusCommissionEmployee basePlusMember
	 ("abc","def","0987654321",250000, 0.15, 5000);

	cout<<"------------test base object--------------------"<<endl;
	testBaseObject();
	cout<<"\n------------test derived object--------------------"<<endl;
	testDerivedObject();

	cout << "------------test copy constructor BasePlusCommissionEmployee--------------------" << endl;
	BasePlusCommissionEmployee basePlusMember2 = basePlusMember;
	cout << basePlusMember2.toString() << endl;

	cout << "------------test copy constructor CommissionEmployee--------------------" << endl;
	CommissionEmployee comMember2 = comMember;
	cout << comMember2.toString() << endl;

	cout << "------------test checkGrossSales function--------------------" << endl;
	double baseline1 = 100000;
	double baseline2 = 5000;
	if (checkGrossSales(comMember, baseline1)) {
		cout << "Commission employee's gross sales exceed " << baseline1 << endl;
	} else {
		cout << "Commission employee's gross sales do not exceed " << baseline1 << endl;
	}

	if (checkGrossSales(basePlusMember, baseline2)) {
		cout << "Base-plus commission employee's gross sales exceed " << baseline2 << endl;
	} else {
		cout << "Base-plus commission employee's gross sales do not exceed " << baseline2 << endl;
	}

}

