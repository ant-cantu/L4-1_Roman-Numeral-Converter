#include <iostream>
#include "romanType.h"

using namespace std;

int main()
{
	romanType romanNum;
	string input;
	bool validInput;

	cout << "Anthony Cantu\t" << "L4-1\t" << "L4-1.exe" << endl;
	cout << endl; //Line Break

	do
	{
		cout << "Enter a roman number or Q/q to Quit: ";
		cin >> input;

		if (input == "Q" || input == "q")
			break;

		romanNum.setRoman(input);
		if (romanNum.romanValid())
		{
			romanNum.romanToPositiveInteger();
			cout << "The equivalent deciaml number of the Roman numeral "
				<< input << " is ";
			romanNum.printPositiveInteger();
			cout << endl << endl;
			validInput = true;
			input.clear();
		}
		else
		{
			validInput = false;
			input.clear();
		}
	} while (!validInput || input != "Q" || input != "q");

	char q;
	cout << "Press any key to Exit.";
	cin.ignore(2, '\n');
	cin.get(q);
	return 0;
}