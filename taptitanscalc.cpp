/********************************************
Written by Fonte Clanton 01/05/2015

Simple Calculator for Tap Titans to determine
the amount of gold needed for a number of
upgrades to heroes.
********************************************/

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

std::string CalcTotal(float, int);

int main() {
	float startVal;
	int numLevels;

	std::cout << std::endl << std::endl << "Enter the starting value: ";
	std::cin >> startVal;

	std::cout << "Enter the number of levels to calculate: ";
	std::cin >> numLevels;
	getchar();

	std:: cout << std::endl << std::endl << "Total gold needed is: " 
		<< CalcTotal(startVal, numLevels) 
		<< std::endl << "Press any key to exit...";

	// Pause at end of execution
	getchar();
	std::cout << std::endl;

	return 0;
}

std::string CalcTotal(float curGold, int numLevels) {
	float total = 0;
	while (numLevels > 0) {
		total += curGold;
		curGold *= 1.075;
		numLevels--;
	}

	// Use comma, period, etc for large numbers
	std::stringstream ss;
	ss.imbue(std::locale(""));

	// Keep two decimals for numbers less than 1000
	if(total < 1000) {
		ss << std::fixed << std::setprecision(2) << total;
		return ss.str();
	}

	// Drop decimals for numbers greater than or equal to 1000
	else {
		ss << std::fixed << int(total);
		return ss.str();
	}		
}
