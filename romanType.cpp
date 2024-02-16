#include <iostream>
#include <string>
#include <cctype>
#include "romanType.h"

using namespace std;

void romanType::setRoman(string nums)
{
	romanNumerals = nums;
	romanValues = 0;

	int len = romanNumerals.length();

	for (int i = 0; i < len; i++)
	{
		romanNumerals[i] = toupper(romanNumerals[i]);	//Convert lowercase to uppercase
	}

	//cout << romanNumerals << endl; //Debug
}

bool romanType::romanValid()
{
	int len = romanNumerals.length();

	//Check if string contains anything besides alpahbet characters and roman numerals
	for (int j = 0; j < len; j++)
	{
		if (!isalpha(romanNumerals[j]))
			return false;
		else
		{
			switch (romanNumerals[j])
			{
			case 'I':
			case 'V':
			case 'X':
			case 'L':
			case 'C':
			case 'D':
			case 'M':
				break;
			default:
				cout << "Invalid Roman Digit" << endl;
				return false;
			}
		}
	}

	//Check if I, X, or C is repeated more than 4 times in a row
	for (int i = 0; i < len; i++)
		if (i < len - 3)
			if (romanNumerals[i] == 'I' || romanNumerals[i] == 'X' || romanNumerals[i] == 'C')
				if (romanNumerals[i] == romanNumerals[i + 1]
					&& romanNumerals[i] == romanNumerals[i + 2]
					&& romanNumerals[i] == romanNumerals[i + 3])
				{
					cout << "Invalid Roman Digit order" << endl;
					return false;
				}

	//Check if V, L, or D is repeated more than once consecutively
	for (int x = 0; x < len; x++)
		if (x < len - 1)
			if (romanNumerals[x] == 'V' || romanNumerals[x] == 'L' || romanNumerals[x] == 'D')
				if (romanNumerals[x] == romanNumerals[x + 1])
				{
					cout << "Invalid Roman Digit order" << endl;
					return false;
				}

	//Block II from preceding V, X, L, C, D, or M
	for (int n = 0; n < len; n++)
	{
		if (n < len - 2)
		{
			if (romanNumerals[n] == 'I' && romanNumerals[n + 1] == 'I')
			{
				switch (romanNumerals[n + 2])
				{
				case 'V':
				case 'X':
				case 'L':
				case 'C':
				case 'D':
				case 'M':
					cout << "Invalid Roman Digit order" << endl;
					return false;
				}
			}
		}
	}
	return true;
}

void romanType::romanToPositiveInteger()
{
	int len = romanNumerals.length();

	//Parse the string input by the user
	for (int i = 0; i < len; i++)
	{
		switch (romanNumerals[i])
		{
		case 'I':
			if (romanNumerals[i + 1] == 'X') //X
			{
				romanValues += 9; 
				i++;
				break;
			}
			else if (romanNumerals[i + 1] == 'V') //IV
			{
				romanValues += 4; 
				i++;
				break;
			}
			else if (romanNumerals[i + 1] == 'I' && romanNumerals[i + 2] == 'I') //III
			{
				romanValues += 3; 
				i += 2;
				break;
			}
			else if (romanNumerals[i + 1] == 'I')	//II
			{
				romanValues += 2; 
				i++;
				break;
			}
			else
				romanValues += 1; //I
			break;
		case 'V':
				romanValues += 5;
			break;
		case 'X':
			if (romanNumerals[i + 1] == 'C')	//C
			{
				romanValues += 90;
				i++;
				break;
			}
			else if (romanNumerals[i + 1] == 'L')	//XL
			{
				romanValues += 40;
				i++;
				break;
			}
			else if (romanNumerals[i + 1] == 'X' && romanNumerals[i + 2] == 'L')	//XXL
			{
				romanValues += 30; 
				i += 2;
				break;
			}
			else
				romanValues += 10; //X
			break;
		case 'L':
			if (romanNumerals[i + 1] == 'D') //LD
			{
				romanValues += 450;
				i++;
				break;
			}
			else
				romanValues += 50;	//L
			break;
		case 'C':
			if (romanNumerals[i + 1] == 'M')	//CM
			{
				romanValues += 900;	
				i++;
				break;
			}
			else
				romanValues += 100;	//C
			break;
		case 'D':
			romanValues += 500;		//D
			break;
		case 'M':
			romanValues += 1000;	//M
		}
	}
}

void romanType::printPositiveInteger() const
{
	cout << romanValues;
}

void romanType::printRoman() const
{
	cout << romanNumerals;
}

romanType::romanType(string nums)
{
	setRoman(nums);
}

romanType::romanType()
{
	romanValues = 0;
	romanNumerals.clear();
}