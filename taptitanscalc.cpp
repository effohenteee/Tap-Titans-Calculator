#include <algorithm>
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

	float total = 0;
	while (numLevels > 0) {
		total += startVal;
		startVal *= 1.075;
		numLevels--;
	}

	return total;
}

void displayPrompt() {
	std::cout << std::endl << "1. Hero Cost Calculator" << std::endl
		<< "2. Monster Health Calculator" << std::endl
		<< "3. Exit" << std::endl
		<< "Please make your choice: ";
}

unsigned long long int calcMonsterHealth(int stage) {
	return 18.5 * pow(1.57, std::min(stage, 150)) * pow(1.17, std::max(stage-150, 0));
}

unsigned int getChoice() {
	unsigned int temp;
	std::cin >> temp;
	getchar();
	if(1 <= temp && temp <= 3) {
		return temp;
	}

	else {
		while(!(1 <= temp && temp <= 3)) {
			std::cout << "Not valid, try again: ";
			std::cin >> temp;
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