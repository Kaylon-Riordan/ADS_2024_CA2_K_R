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
			printTree(treeMap.getBinaryTree(), chooseTreeSortOrder());
			break;
		case 2:
			//write(treeMap.keySet());
			break;
		case 3:
			printTree(chooseFilter(treeMap, chooseFilterField()).getBinaryTree(), chooseTreeSortOrder());
			break;
		default:
			cout << "Unrecognised input, please try again.\n";
			break;
		}
	} while (input != 0);
}

int chooseTreeSortOrder()
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
		case 2:
			return 2;
		case 3:
			return 3;
		default:
			cout << "Unrecognised input, please try again.\n";
			break;
		}
	} while (true);
}
TreeMap<string, carDetails> chooseFilterField()
{
	int input;
	do
	{
		cout << "\nWhat field would you like to filter by: \n1: ID. \n2: Make. \n3: Model. \n4: Year. \n5: Owner. \nChoice:   ";

		cin >> input;
		cout << endl;

		switch (input)
		{
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		case 4:
			return 4;
		case 5:
			return 5;
		default:
			cout << "Unrecognised input, please try again.\n";
			break;
		}
	} while (true);
}
TreeMap<string, carDetails> chooseFilter(TreeMap<string, carDetails> tree, int field)
{
	TreeMap<string, carDetails> newTree;
	switch (field)
	{
	case 1:
		do
		{
			string input;
			cout << "\nWhat ID would you like to filter for: \nChoice:   ";

			cin >> input;
			cout << endl;

			if (tree.containsKey(input))
			{
				newTree.put(input, tree.get(input));
				return newTree;
			}
			else
			{
				cout << "Unrecognised input, please try again.\n";
			}

		} while (true);

		break;
	case 2:
		do
		{
			string input;
			cout << "\nWhat Make would you like to filter for: \nChoice:   ";

			cin >> input;
			cout << endl;

			filterNodes(tree.getBinaryTree().root, newTree);

			if(newTree.size() != 0)
			{
				return newTree;
			}
			else
			{
				cout << "Unrecognised input, please try again.\n";
			}

		} while (true);

		break;
	case 3:
		//tree.printPostOrder();
		break;
	case 4:
		//tree.printPreOrder();
		break;
	case 5:
		//tree.printPostOrder();
		break;
	default:
		cout << "Error occured with sorting.\n";
		break;
	}
}
void filterNodes(BSTNode<Entity<string, carDetails>>* root, TreeMap<string, carDetails> tree, int field)
{
	BSTNode<T> n = *node;
	if (n.getLeft() != nullptr)
	{
		this->printInOrder(n.getLeft());
	}
	cout << n.getItem() << endl;
	if (n.getRight() != nullptr)
	{
		this->printInOrder(n.getRight());
	}
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

void printTree(BinaryTree<Entity<string, carDetails>> tree, int sort)
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