#include "CSVMenu.h"
using namespace std;

void sortByIndexOrFilter()
{
	TreeMap<string, carDetails> cars = readCSVFile();
	cars.keySet().printInOrder();
}

TreeMap<string, carDetails> readCSVFile()
{
	TreeMap<string, carDetails> treeMap;

	fstream read;
	read.open("..\\cars.csv", ios::in);
	string id, make, model, owner;
	int year;
	while (read >> id)
	{
		carDetails details;

		read >> make;
		read >> model;
		read >> year;
		read >> owner;

		details.make = make;
		details.model = model;
		details.year = year;
		details.owner = owner;

		treeMap.put(id, details);
	}

	return treeMap;
}