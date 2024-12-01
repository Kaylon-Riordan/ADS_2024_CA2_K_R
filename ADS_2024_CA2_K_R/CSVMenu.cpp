#include "CSVMenu.h"
using namespace std;

void sortByIndexOrFilter()
{
	chooseIndexOrFilter(readCSVFile());
}

void chooseIndexOrFilter(TreeMap<string, carDetails> treeMap)
{
	int input;
	do
	{
		cout << "\nWhat would you like to view: \n1: View all data. \n2: View index for a specified field. \n3: View filter for a specified value. \n0: Back to main menu. \nChoice:   ";

		cin >> input;
		cout << endl;

		switch (input)
		{
		case 0:
			cout << "Returning to main.\n";
			break;
		case 1:
			print(treeMap.keySet(), chooseSortOrder());
			break;
		case 2:
			//print(treeMap.keySet(), chooseSortOrder());
			break;
		case 3:
			//print(treeMap.getBinaryTree(), chooseSortOrder());
			break;
		default:
			cout << "Unrecognised input, please try again.\n";
			break;
		}
	} while (input != 0);
}

int chooseSortOrder()
{
	int input;
	do
	{
		cout << "\nHow would you like the data sorted: \n1: In order. \n2: Pre order. \n3: Post order. \nChoice:   ";

		cin >> input;
		cout << endl;

		switch (input)
		{
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		default:
			cout << "Unrecognised input, please try again.\n";
			break;
		}
	} while (true);
}

TreeMap<string, carDetails> readCSVFile()
{
	TreeMap<string, carDetails> treeMap;

	fstream read;
	read.open("..\\cars.csv", ios::in);
	string line;
	while (getline(read, line))
	{
		string id, make, model, owner, yearTemp;
		int year;
		carDetails details;
		stringstream row(line);

		getline(row, id, ',');
		getline(row, make, ',');
		getline(row, model, ',');
		getline(row, yearTemp, ',');
		year = stoi(yearTemp);
		getline(row, owner, ',');

		details.make = make;
		details.model = model;
		details.year = year;
		details.owner = owner;

		treeMap.put(id, details);
	}
	return treeMap;
}

template <class T>
void print(BinaryTree<T> tree, int sort)
{
	switch (sort)
	{
	case 1:
		tree.printInOrder();
		break;
	case 2:
		tree.printPreOrder();
		break;
	case 3:
		tree.printPostOrder();
		break;
	default:
		cout << "Error occured with sorting.\n";
		break;
	}
}