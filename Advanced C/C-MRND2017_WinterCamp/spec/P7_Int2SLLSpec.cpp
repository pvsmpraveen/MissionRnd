#include "stdafx.h"
#include "../src/P7_Int2SLL.cpp"
#include <stdio.h>
#include <stdlib.h>
#define NEW(n, t) ((t*) malloc((n)*sizeof(t)))


using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P7_Int2SLLSpec
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

		struct node* newNode(int digit) {
			struct node *node1 = NEW(1, struct node);
			node1->data = digit;
			node1->next = NULL;
			return node1;
		}
	

		
		int LL2int(struct node *head) {
			if (head == NULL)
				return -1;
			int n = 0;
			while (head != NULL) {
				n = n*10 + head->data;
				head = head->next;
			}
			return n;
		}

		[TestMethod]
		void Problem7_Testcase1()
		{
			struct node* head = int2LL(47);
			Assert::AreEqual(47, LL2int(head), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem7_Testcase2()
		{
			struct node* head = int2LL(474);
			Assert::AreEqual(474, LL2int(head), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem7_Testcase3()
		{
			struct node* head = int2LL(4000007);
			Assert::AreEqual(4000007, LL2int(head), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem7_Testcase4()
		{
			struct node* head = int2LL(0);
			Assert::AreEqual(0, LL2int(head), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem7_Testcase5()
		{
			struct node* head = int2LL(-1);
			Assert::AreEqual(NULL == head, true, L"Failed for Invalid case P1", 1, 2);
		};

	};
}
