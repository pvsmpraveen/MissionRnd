#include "stdafx.h"
#include "../src/P9_Combinations.cpp"
#include <string.h>
using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P9_CombinationsSpec
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
		bool stringCompare(char *str1, char*str2) {
			int count[26] = { 0 };
			int count2[26] = { 0 };
			if (strlen(str1) != strlen(str2))
				return false;
			for (int i = 0; str1[i] != '\0'; i++) {
				count[str1[i] - 'a']++;
				count2[str2[i] - 'a']++;
			}
			for (int i = 0; i < 26; i++)  {
				if (count[i] != count2[i])
					return false;
			}
			return true;
		}
		bool Compare(char** ans, char **new_str, int count) {
			bool result;
			for (int i = 0; i < count; i++) {
				result = false;
				for (int j = 0; j < count; j++) {
					if (stringCompare(ans[i], new_str[j])){
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
		void Problem9_Testcase1()
		{
			char str[] = "abc";
			int len = 3, index;
			int count = 7;
				char *ans[7] = { "a", "b", "c", "ab", "ac", "bc", "abc" };
				char **new_str = combinationsof(str);
			Assert::AreEqual(true, Compare(ans, new_str, count), L"Error in NormalString", 1, 2);
		};

		[TestMethod]
		void Problem9_Testcase2()
		{
			char str[] = "";
			int len = 0, index;
			int count = 0;
			char *ans[7] = {""};
			char **new_str = combinationsof(str);
			Assert::AreEqual(true, Compare(ans, new_str, count), L"Error in NormalString", 1, 2);
		};
		[TestMethod]
		void Problem9_Testcase3()
		{
			char str[] = "a";
			int len = 1, index;
			int count = 1;
			char *ans[7] = { "a" };
			char **new_str = combinationsof(str);
			Assert::AreEqual(true, Compare(ans, new_str, count), L"Error in NormalString", 1, 2);
		};
		[TestMethod]
		void Problem9_Testcase4()
		{
			char str[] = "ab";
			int len = 2, index;
			int count = 3;
			char *ans[3] = { "a", "b", "ab"};
			char **new_str = combinationsof(str);
			Assert::AreEqual(true, Compare(ans, new_str, count), L"Error in NormalString", 1, 2);
		};
		[TestMethod]
		void Problem9_Testcase5()
		{
			char str[] = "abcd";
			int len = 4, index;
			int count = 13;
			char *ans[13] = { "a", "b", "c", "d", "ab", "ac", "ad", "bc", "bd", "abc", "acd", "bcd", "abcd" };
			char **new_str = combinationsof(str);
			Assert::AreEqual(true, Compare(ans, new_str, count), L"Error in NormalString", 1, 2);
		};
	};
}
