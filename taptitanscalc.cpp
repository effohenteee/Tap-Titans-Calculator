#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>

#include "taptitanscalc.h"

double calcGold() {
	double startVal;
	int numLevels;

	std::cout << std::endl << std::endl << "Enter the starting value: ";
	std::cin >> startVal;

	std::cout << "Enter the number of levels to calculate: ";
	std::cin >> numLevels;
	getchar();

	return startVal * pow(1.075, numLevels);
}

void displayPrompt() {
	std::cout << std::endl << std::endl << "1. Hero Cost Calculator" << std::endl
		<< "2. Monster Health Calculator" << std::endl
		<< "3. Exit" << std::endl
		<< "Please make your choice: ";
}

unsigned int getChoice() {
	unsigned int temp = getchar() - 48;
	getchar();
	if(1 <= temp && temp <= 3) {
		return temp;
	}

	else {
		while(!(1 <= temp && temp <= 3)) {
			std::cout << "Not valid, try again: ";
			temp = getchar() - 48;
			getchar();
		}

		return temp;
	}
}

void printGold(double cost) {
	// Use comma, period, etc for large numbers
	std::stringstream ss;
	ss.imbue(std::locale(""));

	// Keep two decimals for numbers less than 1000
	if(cost < 1000) {
		ss << std::fixed << std::setprecision(2) << cost;
		std::cout << std::endl << std::endl << "Total gold needed is: " 
			<< ss.str() << std::endl
			<< "Press any key to continue...";
	}

	// Drop decimals for numbers greater than or equal to 1000
	else {
		ss << std::fixed << int(cost);
		std::cout << std::endl << std::endl << "Total gold needed is: " 
			<< ss.str() << std::endl
			<< "Press any key to continue...";
	}

	// Pause at end of execution
	getchar();
	std::cout << std::endl;
}