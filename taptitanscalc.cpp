#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

#include "taptitanscalc.h"

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
