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
		TEST_METHOD(TestTreeMapRemoveKey)
		{
			TreeMap<int, string> treeMap;
			Entity<int, string> A(1, "Pat");
			Entity<int, string> B(2, "Mat");
			treeMap.add(A);
			treeMap.add(B);

			Assert::IsTrue(treeMap.containsKey(1));
			Assert::IsTrue(treeMap.containsKey(2));

			treeMap.removeKey(1);

			Assert::IsFalse(treeMap.containsKey(1));
			Assert::IsTrue(treeMap.containsKey(2));

			treeMap.removeKey(2);

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
		TEST_METHOD(TestTreeMapSize)
		{
			TreeMap<int, string> treeMap;
			Entity<int, string> A(1, "Pat");
			Entity<int, string> B(2, "Mat");
			treeMap.add(A);

			Assert::AreEqual(1, treeMap.size());

			treeMap.add(B);

			Assert::AreEqual(2, treeMap.size());

			treeMap.removeKey(1);

			Assert::AreEqual(1, treeMap.size());

			treeMap.clear();

			Assert::AreEqual(0, treeMap.size());
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

			treeMap.removeKey(1);

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

		TEST_METHOD(TestTreeMapKeySet)
		{
			TreeMap<int, string> treeMap;
			Entity<int, string> A(1, "Pat");
			Entity<int, string> B(2, "Mat");
			Entity<int, string> C(3, "Kat");

			treeMap.add(B);
			treeMap.add(A);
			treeMap.add(C);

			BinaryTree<int> keySet = treeMap.keySet();

			Assert::AreEqual(2, treeMap.getBinaryTree().root->getItem().getKey());
			Assert::AreEqual(2, keySet.root->getItem());
			Assert::AreEqual(1, treeMap.getBinaryTree().root->getLeft()->getItem().getKey());
			Assert::AreEqual(1, keySet.root->getLeft()->getItem());
			Assert::AreEqual(3, treeMap.getBinaryTree().root->getRight()->getItem().getKey());
			Assert::AreEqual(3, keySet.root->getRight()->getItem());
		}

		TEST_METHOD(TestTreeMapPut)
		{
			TreeMap<int, string> treeMap;
			Entity<int, string> A(1, "Pat");
			Entity<int, string> B(2, "Mat");
			treeMap.add(A);
			treeMap.add(B);
			string pat = "Pat";
			string mat = "Mat";
			
			Assert::AreEqual(pat, treeMap.get(1));
			Assert::AreEqual(mat, treeMap.get(2));

			treeMap.put(1, mat);
			treeMap.put(2, pat);

			Assert::AreEqual(mat, treeMap.get(1));
			Assert::AreEqual(pat, treeMap.get(2));
		}

		TEST_METHOD(TestTreeMapSquareBrackets)
		{
			TreeMap<int, string> treeMap;
			Entity<int, string> A(1, "Pat");
			Entity<int, string> B(2, "Mat");
			treeMap.add(A);
			treeMap.add(B);
			string pat = "Pat";
			string mat = "Mat";

			Assert::AreEqual(pat, treeMap[1]);
			Assert::AreEqual(mat, treeMap[2]);
		}
	};
}