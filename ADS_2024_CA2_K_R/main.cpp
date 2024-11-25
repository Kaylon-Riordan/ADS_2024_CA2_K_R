#include "TreeMap.h"

int main()
{
	TreeMap<int, string> treeMap;
	Entity<int, string> A(1, "Pat");
	Entity<int, string> B(2, "Mat");
	treeMap.add(A);
	treeMap.add(B);

	cout << 1 << "Pat" << endl;
	cout << 2 << treeMap.get(1) << endl;
	return 0;
}