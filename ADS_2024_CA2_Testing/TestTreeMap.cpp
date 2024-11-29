#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2024_CA2_K_R/TreeMap.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestTreeMap
{
	TEST_CLASS(TestTreeMap)
	{
		TEST_METHOD(TestTreeMapPut)
		{
			TreeMap<int, string> treeMap;
			string pat = "Pat";
			string mat = "Mat";
			treeMap.put(1, pat);
			string notFound = "";

			Assert::AreEqual(pat, treeMap.get(1));
			Assert::AreEqual(notFound, treeMap.get(2));

			treeMap.put(1, mat);
			treeMap.put(2, pat);

			Assert::AreEqual(mat, treeMap.get(1));
			Assert::AreEqual(pat, treeMap.get(2));
		}
		TEST_METHOD(TestTreeMapRemoveKey)
		{
			TreeMap<int, string> treeMap;
			string pat = "Pat";
			string mat = "Mat";
			treeMap.put(1, pat);
			treeMap.put(2, mat);

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
			string pat = "Pat";
			string mat = "Mat";
			treeMap.put(1, pat);
			treeMap.put(2, mat);

			Assert::IsTrue(treeMap.containsKey(1));
			Assert::IsTrue(treeMap.containsKey(2));

			treeMap.clear();

			Assert::IsFalse(treeMap.containsKey(1));
			Assert::IsFalse(treeMap.containsKey(2));
		}
		TEST_METHOD(TestTreeMapSize)
		{
			TreeMap<int, string> treeMap;
			string pat = "Pat";
			string mat = "Mat";
			treeMap.put(1, pat);

			Assert::AreEqual(1, treeMap.size());

			treeMap.put(2, mat);

			Assert::AreEqual(2, treeMap.size());

			treeMap.removeKey(1);

			Assert::AreEqual(1, treeMap.size());

			treeMap.clear();

			Assert::AreEqual(0, treeMap.size());
		}

		TEST_METHOD(TestTreeMapContainsKey)
		{
			TreeMap<int, string> treeMap;
			string pat = "Pat";
			string mat = "Mat";
			treeMap.put(1, pat);

			Assert::IsTrue(treeMap.containsKey(1));
			Assert::IsFalse(treeMap.containsKey(2));

			treeMap.put(2, mat);

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
			string pat = "Pat";
			string mat = "Mat";
			treeMap.put(1, pat);
			treeMap.put(2, mat);
			string notFound = "";

			Assert::AreEqual(pat, treeMap.get(1));
			Assert::AreEqual(mat, treeMap.get(2));
			Assert::AreEqual(notFound, treeMap.get(3));
		}

		TEST_METHOD(TestTreeMapKeySet)
		{
			TreeMap<int, string> treeMap;
			string pat = "Pat";
			string mat = "Mat";
			string kat = "Kat";
			treeMap.put(2, mat);
			treeMap.put(1, pat);
			treeMap.put(3, kat);

			BinaryTree<int> keySet = treeMap.keySet();

			Assert::AreEqual(2, treeMap.getBinaryTree().root->getItem().getKey());
			Assert::AreEqual(2, keySet.root->getItem());
			Assert::AreEqual(1, treeMap.getBinaryTree().root->getLeft()->getItem().getKey());
			Assert::AreEqual(1, keySet.root->getLeft()->getItem());
			Assert::AreEqual(3, treeMap.getBinaryTree().root->getRight()->getItem().getKey());
			Assert::AreEqual(3, keySet.root->getRight()->getItem());
		}

		TEST_METHOD(TestTreeMapSquareBrackets)
		{
			TreeMap<int, string> treeMap;
			string pat = "Pat";
			string mat = "Mat";
			treeMap.put(1, pat);
			treeMap.put(2, mat);

			Assert::AreEqual(pat, treeMap[1]);
			Assert::AreEqual(mat, treeMap[2]);
		}
	};
}