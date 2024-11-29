#include "SortByInitial.h"
using namespace std;

void sortByInitial()
{
	TreeMap<char, BinaryTree<string>> treeMap = readFile();

	int input;
	do
	{
		cout << "\nWhat would you like to view: \n1: View keys. \n2: View all data. \n0: Exit. \nChoice:   ";

		cin >> input;

		switch (input)
		{
		case 1:
			printKeys(treeMap.keySet(), chooseSortOrder());
			break;
		case 2:
			printAll(treeMap.getBinaryTree(), chooseSortOrder());
			break;
		default:
			cout << "Unrecognised input, please try again.";
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
			cout << "Unrecognised input, please try again.";
			break;
		}
	} while (true);
}

TreeMap<char, BinaryTree<string>> readFile()
{
	TreeMap<char, BinaryTree<string>> treeMap;

	ifstream read;
	read.open("..\\Text.txt");
	string word;
	while (read >> word)
	{
		for (char& letter : word)
		{
			if (letter >= 'a' && letter <= 'z') {}
			else if (letter >= 'A' && letter <= 'Z')
			{
				letter += 32;
			}
			else
			{
				letter = 0;
			}
		}

		if (!treeMap.containsKey(word[0]))
		{
			treeMap.put(word[0], BinaryTree<string>());
		}
		try {
			treeMap.get(word[0]).get(word);
		}
		catch (logic_error)
		{
			treeMap.get(word[0]).add(word);
		}
	}

	return treeMap;
}

void printKeys(BinaryTree<char> tree, int sort)
{
	switch (sort)
	{
	case 1:
		tree.printInOrder();
		break;
	case 2:
		tree.printPreOrder();
		break;
	default:
		tree.printPostOrder();
		break;
	}
}
void printAll(BinaryTree<Entity<char, BinaryTree<string>>> tree, int sort)
{
	switch (sort)
	{
	case 1:
		tree.printInOrder();
		break;
	case 2:
		tree.printPreOrder();
		break;
	default:
		tree.printPostOrder();
		break;
	}
}