#include "TXTMenu.h"
using namespace std;

void sortByInitial()
{
	chooseTree(readTXTFile());
}

void chooseTree(TreeMap<char, BinaryTree<string>> treeMap)
{
	int input;
	do
	{
		cout << "\nWhat would you like to view: \n1: View keys. \n2: View all data. \n0: Back to main menu. \nChoice:   ";

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
			print(treeMap.getBinaryTree(), chooseSortOrder());
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

TreeMap<char, BinaryTree<string>> readTXTFile()
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