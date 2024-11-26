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

	cout << treeMap.get(1) << endl;
	cout << treeMap.get(2) << endl;

	treeMap.put(1, mat);
	treeMap.put(2, pat);

	cout << treeMap.get(1) << endl;
	cout << treeMap.get(2) << endl;
	return 0;
}