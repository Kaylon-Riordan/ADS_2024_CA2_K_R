#include "Print.h"
using namespace std;

template <class T>
void Print::operator () (BinaryTree<T> tree) const {
	display(tree, chooseSortOrder());
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

template <class T>
void display(BinaryTree<T> tree, int sort)
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