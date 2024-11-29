#include "SortByInitial.h"
using namespace std;

void sortByInitial()
{
	TreeMap<char, string> treeMap;

	ifstream read;
	read.open("Text.txt");
	string word;
	while (read >> word)
	{
		for (char& letter : word) 
		{
			if (letter >= 'a' && letter <= 'z'){}
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
			treeMap.put(word[0], word);
		}
		else
		{
			if (treeMap.get(word[0]).find(", " + word) == std::string::npos && treeMap.get(word[0]).find(word + ", ") == std::string::npos)
			{
				treeMap.get(word[0]) += ", " + word;
			}
		}
	}

	cout << "Keys in order: " << endl;
	treeMap.keySet().printInOrder();
	cout << endl << "Keys and values pre order: " << endl;
	treeMap.getBinaryTree().printPreOrder();
}