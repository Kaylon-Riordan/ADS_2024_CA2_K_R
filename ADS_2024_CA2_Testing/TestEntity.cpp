#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2024_CA2_K_R/Entity.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestEntity
{
	TEST_CLASS(TestEntity)
	{
		TEST_METHOD(TestEntityEqualsTrue)
		{
			Entity<int, string> A(1, "John");
			Entity < int, string> B(1, "Joe");
			Assert::IsTrue(A == B);
		}

		TEST_METHOD(TestEntityEqualsFalse)
		{
			Entity<int, string> A(1, "John");
			Entity < int, string> B(2, "Joe");
			Assert::IsFalse(A == B);
		}

		TEST_METHOD(TestEntityGreaterThanTrue)
		{
			Entity<int, string> A(2, "John");
			Entity < int, string> B(1, "Joe");
			Assert::IsTrue(A > B);
		}

		TEST_METHOD(TestEntityGreaterThanEqual)
		{
			Entity<int, string> A(1, "John");
			Entity < int, string> B(1, "Joe");
			Assert::IsFalse(A > B);
		}

		TEST_METHOD(TestEntityGreaterThanFalse)
		{
			Entity<int, string> A(1, "John");
			Entity < int, string> B(2, "Joe");
			Assert::IsFalse(A > B);
		}

		TEST_METHOD(TestEntityLessThanTrue)
		{
			Entity<int, string> A(1, "John");
			Entity < int, string> B(2, "Joe");
			Assert::IsTrue(A < B);
		}

		TEST_METHOD(TestEntityLessThanEqual)
		{
			Entity<int, string> A(1, "John");
			Entity < int, string> B(1, "Joe");
			Assert::IsFalse(A < B);
		}

		TEST_METHOD(TestEntityLessThanFalse)
		{
			Entity<int, string> A(2, "John");
			Entity < int, string> B(1, "Joe");
			Assert::IsFalse(A < B);
		}

	};
}
