#include "TreeMap.h"

int main()
{
	TreeMap<int, string> treeMap;
	Entity<int, string> A(1, "Pat");
	Entity<int, string> B(2, "Mat");
	treeMap.add(A);
	treeMap.add(B);
	string pat = "Pat";
	string mat = "Mat";

	BinaryTree<int> keySet = treeMap.keySet();

	return 0;
}