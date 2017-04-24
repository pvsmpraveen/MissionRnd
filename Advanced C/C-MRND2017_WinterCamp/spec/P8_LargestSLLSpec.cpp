#include "stdafx.h"
#include "../src/P8_LargestSLL.cpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NEW(n, t) ((t*) malloc((n)*sizeof(t)))

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P8_LargestSLLSpec
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

		struct link* newNode(int digit) {
			struct link *node = NEW(1, struct link);
			node->data = digit;
			node->next = NULL;
			return node;
		}
		struct link* int2LL(int n) {
			if (n < 0)
				return NULL;

			struct link *head = (link*)calloc(1, sizeof(link));
			head->data = n % 10;
			n /= 10;
			while (n) {
				link *t = (link *)calloc(1, sizeof(link));
				t->data = n % 10;
				n /= 10;
				t->next = head;
				head = t;
			}
			return head;
		}
		
		[TestMethod]
		void Problem8_Testcase1()
		{
			struct link *one = int2LL(47);
			struct link *two = int2LL(100);

			Assert::AreEqual(2, compare(one, two), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem8_Testcase2()
		{
			struct link *one = int2LL(100);
			struct link *two = int2LL(47);
			Assert::AreEqual(1, compare(one, two), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem8_Testcase3()
		{
			struct link *one = int2LL(100);
			struct link *two = NULL;
			Assert::AreEqual(1, compare(one, two), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem8_Testcase4()
		{
			struct link *one = NULL;
			struct link *two = NULL;
			Assert::AreEqual(-1, compare(one, two), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem8_Testcase5()
		{
			struct link *one = int2LL(1122);
			struct link *two = int2LL(1122);
			Assert::AreEqual(0, compare(one, two), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem8_Testcase6()
		{
			struct link *one = int2LL(11223);
			struct link *two = int2LL(1122);
			Assert::AreEqual(1, compare(one, two), L"Failed for Invalid case P1", 1, 2);
		};
		[TestMethod]
		void Problem8_Testcase7()
		{
			struct link *one = int2LL(1122);
			struct link *two = int2LL(11220);
			Assert::AreEqual(2, compare(one, two), L"Failed for Invalid case P1", 1, 2);
		};
		[TestMethod]
		void Problem8_Testcase8()
		{
			struct link *one = int2LL(1122);
			struct link *two = int2LL(11220);
			struct link *zero = newNode(0);
			zero->next = one;
			Assert::AreEqual(2, compare(zero,
				two), L"Failed for Invalid case P1", 1, 2);
		};
	};
}
