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
			cout << left << setw(25) << setfill(' ') << "| ID";
			cout << left << setw(20) << setfill(' ') << "| Make";
			cout << left << setw(20) << setfill(' ') << "| Model";
			cout << left << setw(10) << setfill(' ') << "| Year";
			cout << left << setw(25) << setfill(' ') << "| Owner" << "|\n";
			printTree(treeMap.getBinaryTree().root);
			break;
		case 2:
			printTreeIndex(chooseIndexField(treeMap).getBinaryTree().root);
			break;
		case 3:
			printTree(chooseFilterField(treeMap).getBinaryTree().root);
			break;
		default:
			cout << "Unrecognised input, please try again.\n";
			break;
		}
	} while (input != 0);
}

TreeMap<string, int> chooseIndexField(TreeMap<string, carDetails> tree)
{
	int field;
	do
	{
		cout << "\nWhat field would you like to filter by: \n1: ID. \n2: Make. \n3: Model. \n4: Year. \n5: Owner. \nChoice:   ";

		cin >> field;
		cout << endl;

		TreeMap<string, int> newTree;

		indexNodes(tree.getBinaryTree().root, newTree, field);
		cout << left << setw(25) << setfill(' ') << "| Index";
		cout << left << setw(10) << setfill(' ') << "| Count" << "|\n";
		return newTree;
	} while (true);
}
TreeMap<string, carDetails> chooseFilterField(TreeMap<string, carDetails> tree)
{
	int field;
	do
	{
		cout << "\nWhat field would you like to filter by: \n1: ID. \n2: Make. \n3: Model. \n4: Year. \n5: Owner. \nChoice:   ";

		cin >> field;
		cout << endl;

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
					cout << left << setw(25) << setfill(' ') << "| ID";
					cout << left << setw(20) << setfill(' ') << "| Make";
					cout << left << setw(20) << setfill(' ') << "| Model";
					cout << left << setw(10) << setfill(' ') << "| Year";
					cout << left << setw(25) << setfill(' ') << "| Owner" << "|\n";
					return newTree;
				}
				else
				{
					cout << "Unrecognised input, please try again.\n";
				}
			} while (true);
			break;
		case 2: case 3: case 4: case 5:
			do
			{
				// clear cin so its not reading old inputs, was causing repeating loop bug
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				string input;
				cout << "\nWhat data would you like to filter for: \nChoice:   ";

				getline(cin, input);
				cout << endl;

				filterNodes(tree.getBinaryTree().root, newTree, field, input);
				if (newTree.size() != 0)
				{
					cout << left << setw(25) << setfill(' ') << "| ID";
					cout << left << setw(20) << setfill(' ') << "| Make";
					cout << left << setw(20) << setfill(' ') << "| Model";
					cout << left << setw(10) << setfill(' ') << "| Year";
					cout << left << setw(25) << setfill(' ') << "| Owner" << "|\n";
					return newTree;
				}
				else
				{
					cout << "Unrecognised input, please try again.\n";
				}
			} while (true);

			break;
		default:
			cout << "Unrecognised input, please try again.\n";
			break;
		}
	} while (true);
}

void indexNodes(BSTNode<Entity<string, carDetails>>* root, TreeMap<string, int>& tree, int field)
{
	BSTNode<Entity<string, carDetails>> node = *root;

	switch (field)
	{
	case 1:
		if (!tree.containsKey(node.getItem().getKey()))
		{
			tree.put(node.getItem().getKey(), 0);
		}
		tree.put(node.getItem().getKey(), tree.get(node.getItem().getKey()) + 1);
		break;
	case 2:
		if (!tree.containsKey(node.getItem().getValue().make))
		{
			tree.put(node.getItem().getValue().make, 0);
		}
		tree.put(node.getItem().getValue().make, tree.get(node.getItem().getValue().make) + 1);
		break;
	case 3:
		if (!tree.containsKey(node.getItem().getValue().model))
		{
			tree.put(node.getItem().getValue().model, 0);
		}
		tree.put(node.getItem().getValue().model, tree.get(node.getItem().getValue().model) + 1);
		break;
	case 4:
		if (!tree.containsKey(to_string(node.getItem().getValue().year)))
		{
			tree.put(to_string(node.getItem().getValue().year), 0);
		}
		tree.put(to_string(node.getItem().getValue().year), tree.get(to_string(node.getItem().getValue().year)) + 1);
		break;
	case 5:
		if (!tree.containsKey(node.getItem().getValue().owner))
		{
			tree.put(node.getItem().getValue().owner, 0);
		}
		tree.put(node.getItem().getValue().owner, tree.get(node.getItem().getValue().owner) + 1);
		break;
	default:
		cout << "Error with field input.\n";
		break;
	}

	if (node.getLeft() != nullptr)
	{
		indexNodes(node.getLeft(), tree, field);
	}
	if (node.getRight() != nullptr)
	{
		indexNodes(node.getRight(), tree, field);
	}
}
void filterNodes(BSTNode<Entity<string, carDetails>>* root, TreeMap<string, carDetails>& tree, int field, string input)
{
	BSTNode<Entity<string, carDetails>> node = *root;
	switch (field)
	{
	case 2:
		if (node.getItem().getValue().make == input)
		{
			tree.put(node.getItem().getKey(), node.getItem().getValue());
		}
		break;
	case 3:
		if (node.getItem().getValue().model == input)
		{
			tree.put(node.getItem().getKey(), node.getItem().getValue());
		}
		break;
	case 4:
		if (to_string(node.getItem().getValue().year) == input)
		{
			tree.put(node.getItem().getKey(), node.getItem().getValue());
		}
		break;
	case 5:
		if (node.getItem().getValue().owner == input)
		{
			tree.put(node.getItem().getKey(), node.getItem().getValue());
		}
		break;
	default:
		cout << "Error with field input.\n";
		break;
	}

	if (node.getLeft() != nullptr)
	{
		filterNodes(node.getLeft(), tree, field, input);
	}
	if (node.getRight() != nullptr)
	{
		filterNodes(node.getRight(), tree, field, input);
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

void printTree(BSTNode<Entity<string, carDetails>>* root)
{
	BSTNode<Entity<string, carDetails>> node = *root;

	cout << left << setw(25) << setfill(' ') << "| " + node.getItem().getKey();
	cout << left << setw(20) << setfill(' ') << "| " + node.getItem().getValue().make;
	cout << left << setw(20) << setfill(' ') << "| " + node.getItem().getValue().model;
	cout << left << setw(10) << setfill(' ') << "| " + to_string(node.getItem().getValue().year);
	cout << left << setw(25) << setfill(' ') << "| " + node.getItem().getValue().owner << "|\n";;

	if (node.getLeft() != nullptr)
	{
		printTree(node.getLeft());
	}
	if (node.getRight() != nullptr)
	{
		printTree(node.getRight());
	}
}
void printTreeIndex(BSTNode<Entity<string, int>>* root)
{
	BSTNode<Entity<string, int>> node = *root;

	cout << left << setw(25) << setfill(' ') << "| " + node.getItem().getKey();
	cout << left << setw(10) << setfill(' ') << "| " + to_string(node.getItem().getValue()) << "|\n";;

	if (node.getLeft() != nullptr)
	{
		printTreeIndex(node.getLeft());
	}
	if (node.getRight() != nullptr)
	{
		printTreeIndex(node.getRight());
	}
}