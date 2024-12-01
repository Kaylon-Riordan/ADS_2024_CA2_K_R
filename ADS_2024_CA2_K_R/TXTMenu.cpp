#include "TXTMenu.h"
using namespace std;

void sortByInitial()
{
	chooseTree(readTXTFile());
}

void chooseTree(TreeMap<char, BinaryTree<string>> treeMap)
{
	Print write;
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
			write(treeMap.keySet());
			break;
		case 2:
			write(treeMap.getBinaryTree());
			break;
		default:
			cout << "Unrecognised input, please try again.\n";
			break;
		}
	} while (input != 0);
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