/********************************************
Written by Fonte Clanton 01/05/2015

Simple Calculator for Tap Titans to determine
the amount of gold needed for a number of
upgrades to heroes.
********************************************/

#include <cstdio>
#include <iostream>
#include <string>
#include "taptitanscalc.h"

int main() {
	float startVal;
	int numLevels;

	std::cout << std::endl << std::endl << "Enter the starting value: ";
	std::cin >> startVal;

	std::cout << "Enter the number of levels to calculate: ";
	std::cin >> numLevels;
	getchar();

	std::cout << std::endl << std::endl << "Total gold needed is: " 
		<< CalcTotal(startVal, numLevels) 
		<< std::endl << "Press any key to exit...";

	// Pause at end of execution
	getchar();
	std::cout << std::endl;

	return 0;
}