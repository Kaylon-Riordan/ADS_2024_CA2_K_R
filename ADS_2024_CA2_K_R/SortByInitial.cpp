#include "SortByInitial.h"
using namespace std;

void sortByInitial()
{
	TreeMap<char, BinaryTree<string>> treeMap = readFile();

	printKeys(treeMap.keySet());
	printAll(treeMap.getBinaryTree());
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

void printKeys(BinaryTree<char> tree)
{
	cout << "Keys in order: " << endl;
	tree.printInOrder();
}
void printAll(BinaryTree<Entity<char, BinaryTree<string>>> tree)
{
	cout << endl << "Keys and values pre order: " << endl;
	tree.printPreOrder();
}