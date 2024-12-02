#include "TreeMap.h"
#include "TXTMenu.h"
#include "CSVMenu.h"

int main()
{
	int input;
	do 
	{
		// prompt the user with choices of classes to run
		cout << "\nWhich class would you like to run: \n1: Sort words from text file by their first letter. \n2: Sort car data from CSV file. \n0: Exit. \nChoice:   ";

		// take input
		cin >> input;
		cout << endl;

		// use switch to determin what to do with input
		switch (input) 
		{
		case 0:
			cout << "Exiting.";
			break;
		case 1:
			// run appropriate class
			chooseTree();
			break;
		case 2:
			chooseIndexOrFilter();
			break;
		default:
			// print an error message if input dosnt match options
			cout << "Unrecognised input, please try again.\n";
			break;
		}
	} 
	// repeat until 0 is inputed to quit
	while (input != 0);

	return 0;
}