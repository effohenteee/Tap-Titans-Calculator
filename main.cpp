/********************************************
Written by Fonte Clanton 01/05/2015

Simple Calculator for Tap Titans to determine
the amount of gold needed for a number of
upgrades to heroes.
********************************************/


#include <iostream>
#include <string>
#include "taptitanscalc.h"



int main() {
	unsigned int choice = 0;

	while(choice != 3) {
		switch(choice) {
			// Init
			case 0: {
				displayPrompt();
				choice = getChoice();
			}
			break;

			case 1: {
				printGold(calcGold());
				choice = 0;
			}
			break;

			case 2: {
				printMonsterHealth();
				choice = 0;
			}
			break;
		}
	}

	std::cout << std::endl;
	return 0;
}