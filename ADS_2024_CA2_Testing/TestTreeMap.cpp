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

		TEST_METHOD(TestTreeMapContainsKeyTrue)
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
	};
}