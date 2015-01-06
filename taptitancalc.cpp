/********************************************
Written by Fonte Clanton 01/05/2015

Simple Calculator for Tap Titans to determine
the amount of gold needed for a number of
upgrades to heroes.
********************************************/

#include <iostream>
#include <iomanip>

float CalcTotal(float, int);

int main() {
	float startVal;
	int numLevels;

	std::cout << std::endl << std::endl << "Enter the starting value: ";
	std::cin >> startVal;

	std:: cout << "Enter the number of levels to calculate: ";
	std::cin >> numLevels;

	std:: cout << std::endl << std::endl << "Total gold needed is: " << 
		CalcTotal(startVal, numLevels) << std::setprecision(2) << std::endl;


	return 0;
}

float CalcTotal(float curGold, int numLevels) {
	float total = 0;
	while (numLevels > 0) {
		total += curGold;
		curGold *= 1.075;
		numLevels--;
	}

	return total;
}