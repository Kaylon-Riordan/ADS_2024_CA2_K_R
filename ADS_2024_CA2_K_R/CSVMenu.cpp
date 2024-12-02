#include "CSVMenu.h"
using namespace std;

void chooseIndexOrFilter()
{
	TreeMap<string, carDetails> treeMap = readCSVFile();
	int input;
	do
	{
		cout << "\nWhat would you like to view: \n1: View all data. \n2: View index for a specified field. \n3: View filter for a specified value. \n0: Back to main menu. \nChoice:   ";

		cin >> input;
		cout << endl;

		switch (input)
		{
		// return to main menu by breaking
		case 0:
			cout << "Returning to main.\n";
			break;
		// call the necessary function relative to user input to print, all data, indexed data, or filtered data
		case 1:
			// print the header line before recursivley printing the data
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
		cout << "\nWhat field would you like to index: \n1: ID. \n2: Make. \n3: Model. \n4: Year. \n5: Owner. \nChoice:   ";

		cin >> field;
		cout << endl;

		TreeMap<string, int> newTree;

		// call the nodes recursively and count them by specified value for the index
		indexNodes(tree.getBinaryTree().root, newTree, field);
		// print the header line before printing the data
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
			// have one code for id as it functions differently as the key
		case 1:
			do
			{
				string input;
				cout << "\nWhat ID would you like to filter for: \nChoice:   ";

				cin >> input;
				cout << endl;

				// if the filtered id is present then print the one line with that unique id
				if (tree.containsKey(input))
				{
					newTree.put(input, tree.get(input));
					// print the header line before recursivley printing the data
					cout << left << setw(25) << setfill(' ') << "| ID";
					cout << left << setw(20) << setfill(' ') << "| Make";
					cout << left << setw(20) << setfill(' ') << "| Model";
					cout << left << setw(10) << setfill(' ') << "| Year";
					cout << left << setw(25) << setfill(' ') << "| Owner" << "|\n";
					return newTree;
				}
				// if its not present, prompt user for a diffrent id choice
				else
				{
					cout << "Unrecognised input, please try again.\n";
				}
			} while (true);
			break;
		// run same code for last 4 data pieces as they are all stored the same in carData in entity value
		case 2: case 3: case 4: case 5:
			do
			{
				// clear cin so its not reading old inputs, was causing repeating loop bug
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				string input;
				cout << "\nWhat data would you like to filter for: \nChoice:   ";

				// use get line to not stop at spaces in the owner category
				getline(cin, input);
				cout << endl;

				// run the nodes recurisevly, only returning those that match the filter
				filterNodes(tree.getBinaryTree().root, newTree, field, input);
				if (newTree.size() != 0)
				{
					// print the header line before recursivley printing the data
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

// pass in tree by referance so i can just add to it without returning anything
void indexNodes(BSTNode<Entity<string, carDetails>>* root, TreeMap<string, int>& tree, int field)
{
	BSTNode<Entity<string, carDetails>> node = *root;

	switch (field)
	{
	case 1:
		// if the tree dosnt already contain the current nodes id, then add it
		if (!tree.containsKey(node.getItem().getKey()))
		{
			tree.put(node.getItem().getKey(), 0);
		}
		// every time this key comes up, increase the counter in value by 1
		tree.put(node.getItem().getKey(), tree.get(node.getItem().getKey()) + 1);
		break;
	// all subsquent cases are identical to 1, just using diffrent parts of the car data
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

	// recursively call left, then right
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
	// skip case 1 as this code was done in filter field instead because each id is unique so recusion is unnecesary
	case 2:
		// if the make matches the user filter then add the node to the tree
		if (node.getItem().getValue().make == input)
		{
			tree.put(node.getItem().getKey(), node.getItem().getValue());
		}
		break;
	// repeat for other data sectionss
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

	// recursively call left, then right
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

	// open the csv file
	fstream read;
	read.open("..\\cars.csv", ios::in);
	string line;
	// read whole lines at a time to ge the 5 data points
	while (getline(read, line))
	{
		string id, make, model, owner, yearTemp;
		int year;
		carDetails details;
		// create a string stream so i can parse it by commas to get my data
		stringstream row(line);

		// read in each data point after aeach comma
		getline(row, id, ',');
		getline(row, make, ',');
		getline(row, model, ',');
		getline(row, yearTemp, ',');
		// convert year to int
		year = stoi(yearTemp);
		getline(row, owner, ',');

		// create a carDetails, with the data
		details.make = make;
		details.model = model;
		details.year = year;
		details.owner = owner;

		// return a tree map with the id, and the other 4 details
		treeMap.put(id, details);
	}
	return treeMap;
}

// print function for all data, or filtered data
void printTree(BSTNode<Entity<string, carDetails>>* root)
{
	// dereference node pointer
	BSTNode<Entity<string, carDetails>> node = *root;

	// print out all data in a formated manor 
	// using setw to decide the length of each print, and setfill to fill in the rest of the space determined by setw
	cout << left << setw(25) << setfill(' ') << "| " + node.getItem().getKey();
	cout << left << setw(20) << setfill(' ') << "| " + node.getItem().getValue().make;
	cout << left << setw(20) << setfill(' ') << "| " + node.getItem().getValue().model;
	cout << left << setw(10) << setfill(' ') << "| " + to_string(node.getItem().getValue().year);
	cout << left << setw(25) << setfill(' ') << "| " + node.getItem().getValue().owner << "|\n";;

	// recursively call left, then right
	if (node.getLeft() != nullptr)
	{
		printTree(node.getLeft());
	}
	if (node.getRight() != nullptr)
	{
		printTree(node.getRight());
	}
}
// print function for indexed data
void printTreeIndex(BSTNode<Entity<string, int>>* root)
{
	// same logic as other print
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