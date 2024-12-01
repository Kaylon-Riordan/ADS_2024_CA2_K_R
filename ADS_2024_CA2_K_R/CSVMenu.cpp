#include "CSVMenu.h"
using namespace std;

void sortByIndexOrFilter()
{
	TreeMap<string, carDetails> cars = readCSVFile();
	cars.keySet().printInOrder();
}

void chooseIndexOrFilter(TreeMap<char, BinaryTree<string>> treeMap)
{

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