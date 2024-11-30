#include "TreeMap.h"
#include "TXTMenu.h"
#include "CSVMenu.h"

int main()
{
	int input;
	do 
	{
		cout << "\nWhich class would you like to run: \n1: Sort words from text file by their first letter. \n2: Sort car data from CSV file. \n0: Exit. \nChoice:   ";

		cin >> input;
		cout << endl;

		switch (input) 
		{
		case 0:
			cout << "Exiting.";
			break;
		case 1:
			sortByInitial();
			break;
		case 2:
			sortByIndexOrFilter();
			break;
		default:
			cout << "Unrecognised input, please try again.\n";
			break;
		}
	} 
	while (input != 0);

	return 0;
}