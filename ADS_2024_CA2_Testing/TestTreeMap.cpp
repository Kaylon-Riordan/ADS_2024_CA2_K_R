#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2024_CA2_K_R/TreeMap.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestTreeMap
{
	TEST_CLASS(TestTreeMap)
	{
		TEST_METHOD(TestTreeMapAdd)
		{
			TreeMap<int, string> treeMap;
			Entity<int, string> A(1, "Pat");
			Entity<int, string> B(2, "Mat");

			Assert::IsFalse(treeMap.containsKey(1));
			Assert::IsFalse(treeMap.containsKey(2));

			treeMap.add(A);

			Assert::IsTrue(treeMap.containsKey(1));
			Assert::IsFalse(treeMap.containsKey(2));

			treeMap.add(B);

			Assert::IsTrue(treeMap.containsKey(1));
			Assert::IsTrue(treeMap.containsKey(2));
		}
		TEST_METHOD(TestTreeMapRemove)
		{
			TreeMap<int, string> treeMap;
			Entity<int, string> A(1, "Pat");
			Entity<int, string> B(2, "Mat");
			treeMap.add(A);
			treeMap.add(B);

			Assert::IsTrue(treeMap.containsKey(1));
			Assert::IsTrue(treeMap.containsKey(2));

			treeMap.remove(A);

			Assert::IsFalse(treeMap.containsKey(1));
			Assert::IsTrue(treeMap.containsKey(2));

			treeMap.remove(B);

			Assert::IsFalse(treeMap.containsKey(1));
			Assert::IsFalse(treeMap.containsKey(2));
		}
		TEST_METHOD(TestTreeMapClear)
		{
			TreeMap<int, string> treeMap;
			Entity<int, string> A(1, "Pat");
			Entity<int, string> B(2, "Mat");
			treeMap.add(A);
			treeMap.add(B);

			Assert::IsTrue(treeMap.containsKey(1));
			Assert::IsTrue(treeMap.containsKey(2));

			treeMap.clear();

			Assert::IsFalse(treeMap.containsKey(1));
			Assert::IsFalse(treeMap.containsKey(2));
		}
		TEST_METHOD(TestTreeMapCount)
		{
			TreeMap<int, string> treeMap;
			Entity<int, string> A(1, "Pat");
			Entity<int, string> B(2, "Mat");
			treeMap.add(A);

			Assert::AreEqual(1, treeMap.count());

			treeMap.add(B);

			Assert::AreEqual(2, treeMap.count());

			treeMap.remove(A);

			Assert::AreEqual(1, treeMap.count());

			treeMap.clear();

			Assert::AreEqual(0, treeMap.count());
		}

		TEST_METHOD(TestTreeMapContainsKey)
		{
			TreeMap<int, string> treeMap;
			Entity<int, string> A(1, "Pat");
			Entity<int, string> B(2, "Mat");
			treeMap.add(A);

			Assert::IsTrue(treeMap.containsKey(1));
			Assert::IsFalse(treeMap.containsKey(2));

			treeMap.add(B);

			Assert::IsTrue(treeMap.containsKey(1));
			Assert::IsTrue(treeMap.containsKey(2));

			treeMap.remove(A);

			Assert::IsFalse(treeMap.containsKey(1));
			Assert::IsTrue(treeMap.containsKey(2));

			treeMap.clear();

			Assert::IsFalse(treeMap.containsKey(1));
			Assert::IsFalse(treeMap.containsKey(2));
		}
		TEST_METHOD(TestTreeMapGetByKey)
		{
			TreeMap<int, string> treeMap;
			Entity<int, string> A(1, "Pat");
			Entity<int, string> B(2, "Mat");
			treeMap.add(A);
			treeMap.add(B);
			string pat = "Pat";
			string mat = "Mat";
			string notFound = "";

			Assert::AreEqual(pat, treeMap.get(1));
			Assert::AreEqual(mat, treeMap.get(2));
			Assert::AreEqual(notFound, treeMap.get(3));
		}

		//TEST_METHOD(TestTreeMapKeySet)
		//{
		//	TreeMap<int, string> treeMap;
		//	Entity<int, string> A(1, "Pat");
		//	Entity<int, string> B(2, "Mat");
		//	Entity<int, string> C(3, "Ted");
		//	Entity<int, string> D(4, "Bill");
		//	Entity<int, string> E(5, "Jim");
		//	Entity<int, string> F(6, "Roy");

		//	treeMap.add(C);
		//	treeMap.add(B);
		//	treeMap.add(A);
		//	treeMap.add(E);
		//	treeMap.add(D);
		//	treeMap.add(F);

		//	BinaryTree<int> keySet = treeMap.keySet();

		//	/*Assert::AreEqual(treeMap.getBinaryTree().root->getItem().getKey(), keySet.root->getItem());*/

		//	Assert::AreEqual(treeMap.getBinaryTree().root->getLeft()->getItem().getKey(), 3);
		//	/*Assert::AreEqual(3, keySet.root->getItem());*/

		//	/*Assert::AreEqual(A, treeMap.getBinaryTree().root->getItem());
		//	Assert::AreEqual(B, treeMap.getBinaryTree().root->getLeft()->getItem());
		//	Assert::AreEqual(C, treeMap.getBinaryTree().root->getLeft()->getLeft()->getItem());
		//	Assert::AreEqual(D, treeMap.getBinaryTree().root->getRight()->getItem());
		//	Assert::AreEqual(E, treeMap.getBinaryTree().root->getRight()->getLeft()->getItem());
		//	Assert::AreEqual(F, treeMap.getBinaryTree().root->getRight()->getRight()->getItem());*/
		//}
	};
}