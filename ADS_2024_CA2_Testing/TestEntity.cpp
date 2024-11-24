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
			Entity<int, string> A(1, "Pat");
			Entity < int, string> B(1, "Mat");
			Assert::IsTrue(A == B);
		}
		TEST_METHOD(TestEntityEqualsFalse)
		{
			Entity<int, string> A(1, "Pat");
			Entity < int, string> B(2, "Mat");
			Assert::IsFalse(A == B);
		}

		TEST_METHOD(TestEntityGreaterThanTrue)
		{
			Entity<int, string> A(2, "Pat");
			Entity < int, string> B(1, "Mat");
			Assert::IsTrue(A > B);
		}
		TEST_METHOD(TestEntityGreaterThanEqual)
		{
			Entity<int, string> A(1, "Pat");
			Entity < int, string> B(1, "Mat");
			Assert::IsFalse(A > B);
		}
		TEST_METHOD(TestEntityGreaterThanFalse)
		{
			Entity<int, string> A(1, "Pat");
			Entity < int, string> B(2, "Mat");
			Assert::IsFalse(A > B);
		}

		TEST_METHOD(TestEntityLessThanTrue)
		{
			Entity<int, string> A(1, "Pat");
			Entity < int, string> B(2, "Mat");
			Assert::IsTrue(A < B);
		}
		TEST_METHOD(TestEntityLessThanEqual)
		{
			Entity<int, string> A(1, "Pat");
			Entity < int, string> B(1, "Mat");
			Assert::IsFalse(A < B);
		}
		TEST_METHOD(TestEntityLessThanFalse)
		{
			Entity<int, string> A(2, "Pat");
			Entity < int, string> B(1, "Mat");
			Assert::IsFalse(A < B);
		}

	};
}
