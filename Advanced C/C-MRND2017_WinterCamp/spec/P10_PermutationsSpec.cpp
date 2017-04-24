#include "stdafx.h"
#include "../src/P10_Permutations.cpp"
#include <string.h>
using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P10_PermutationsSpec
	{
	private:
		TestContext^ testContextInstance;

	public:
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
#pragma endregion 
		bool Compare(char** ans, char **new_str, int count) {
			bool result;
			for (int i = 0; i < count; i++) {
				result = false;
				for (int j = 0; j < count; j++) {
					if (strcmp(ans[i], new_str[j]) == 0){
						result = true;
						break;
					}
				}
				if (result == false)
					return false;
			}
			return true;
		}
		[TestMethod]
		void Problem10_Testcase1()
		{
			char str[] = "abc";
			int len = 3, index;
			int count = 6;
			char *ans[6] = { "abc", "acb", "bac", "bca", "cab", "cba" };
			char **new_str = permutationsof(str);
			Assert::AreEqual(true, Compare(ans, new_str, count), L"Error in NormalString", 1, 2);
		};

		[TestMethod]
		void Problem10_Testcase2()
		{
			char str[] = "";
			int len = 0, index;
			int count = 0;
			char *ans[1] = {""};
			char **new_str = permutationsof(str);
			Assert::AreEqual(true, Compare(ans, new_str, count), L"Error in NormalString", 1, 2);
		};
		[TestMethod]
		void Problem10_Testcase3()
		{
			char str[] = "a";
			int len = 1, index;
			int count = 1;
			char *ans[1] = { "a" };
			char **new_str = permutationsof(str);
			Assert::AreEqual(true, Compare(ans, new_str, count), L"Error in NormalString", 1, 2);
		};
		[TestMethod]
		void Problem10_Testcase4()
		{
			char str[] = "ab";
			int len = 2, index;
			int count = 2;
			char *ans[2] = { "ab", "ba"};
			char **new_str = permutationsof(str);
			Assert::AreEqual(true, Compare(ans, new_str, count), L"Error in NormalString", 1, 2);
		};
		[TestMethod]
		void Problem10_Testcase5()
		{
			char str[] = "abcd";
			int len = 4, index;
			int count = 13;
			char *ans[24] = { "abcd", "abdc", "acbd", "acdb", "adbc", "adcb", "bacd", "badc", "bcad", "bcda", "bdac", "bdca",
				"cabd", "cadb", "cbad", "cbda", "cdab", "cdba", "dabc", "dacb", "dbac", "dbca", "dcab", "dcba" };
	
			char **new_str = permutationsof(str);
			Assert::AreEqual(true, Compare(ans, new_str, count), L"Error in NormalString", 1, 2);
		};
	};
}
