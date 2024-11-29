#include "TreeMap.h"
#include "SortByInitial.h"

int main()
{
	int input;
	do 
	{
		cout << "\nWhich class would you like to run: \n1: Sort words in text file by their first letter. \n2: Sort car data from CSV file. \n0: Exit. \nChoice:   ";

		cin >> input;

		switch (input) 
		{
		case 1:
			sortByInitial();
			break;
		case 2:
			//CSVMenu();
			break;
		default:
			cout << "Unrecognised input, please try again.";
			break;
		}
	} 
	while (input != 0);

	return 0;
}