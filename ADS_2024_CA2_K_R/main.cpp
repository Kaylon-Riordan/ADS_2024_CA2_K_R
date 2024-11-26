#include "TreeMap.h"

int main()
{
	TreeMap<int, string> treeMap;
	Entity<int, string> A(1, "Pat");
	Entity<int, string> B(2, "Mat");
	Entity<int, string> C(3, "Ted");
	Entity<int, string> D(4, "Bill");
	Entity<int, string> E(5, "Jim");
	Entity<int, string> F(6, "Roy");

	treeMap.add(C);
	treeMap.add(B);
	treeMap.add(A);
	treeMap.add(E);
	treeMap.add(D);
	treeMap.add(F);

	BinaryTree<int> keySet = treeMap.keySet();

	//cout << treeMap.getBinaryTree().root->getItem().getKey() << endl;
	//cout << keySet.root->getItem() << endl;

	return 0;
}