#pragma once
#include <string>

class romanType
{
public:
	void setRoman(std::string nums);
	//Function to set the roman numerals given
	//by the user to the romanNumerals string variable
	//
	//

	bool romanValid();
	//Function to check if the users input is valid
	//
	//

	void romanToPositiveInteger();
	//Function to convert the roman numerals input
	//by the user into a positive integer
	//
	//

	void printPositiveInteger() const;
	//Function to print the conversion of the roman
	//numerals to the positive integer
	//
	//

	void printRoman() const;
	//Function to print the roman numerals in their
	//original form
	//
	//

	romanType(std::string nums);

	romanType();

private:
	std::string romanNumerals;
	int romanValues;
};

