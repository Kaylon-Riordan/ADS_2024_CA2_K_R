#include "TXTMenu.h"
using namespace std;

void chooseTree()
{
	TreeMap<char, BinaryTree<string>> treeMap = readTXTFile();
	int input;
	do
	{
		cout << "\nWhat would you like to view: \n1: View keys. \n2: View all data. \n0: Back to main menu. \nChoice:   ";
		// take user input
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
		// make sure the user is inputing an acceptable number for choosing sort order, else loop
		switch (input)
		{
		case 1: case 2: case 3:
			return input;
		default:
			cout << "Unrecognised input, please try again.\n";
			break;
		}
	} while (true);
}

TreeMap<char, BinaryTree<string>> readTXTFile()
{
	TreeMap<char, BinaryTree<string>> treeMap;

	// open the file with an ifstream
	ifstream read;
	read.open("..\\Text.txt");
	string word;
	// while the file has more words, seperated by spaces, keep reading 1 by 1
	while (read >> word)
	{
		for (char& letter : word)
		{
			// ignore non letters and set everything to lower case
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

		// this starting letter isnt in the tree map yet, then add it
		if (!treeMap.containsKey(word[0]))
		{
			treeMap.put(word[0], BinaryTree<string>());
		}
		// try to get the current word, to stop duplicates
		try {
			treeMap.get(word[0]).get(word);
		}
		// if the word isnt found, then add it
		catch (logic_error)
		{
			treeMap.get(word[0]).add(word);
		}
	}

	return treeMap;
}

// print in the order chosen by the user
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