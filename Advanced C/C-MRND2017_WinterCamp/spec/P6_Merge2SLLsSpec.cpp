#include "stdafx.h"
#include "../src/P6_Merge2SLLs.cpp"
#include<malloc.h>
#include <string.h>

#define NEW(n, t) ((t*) malloc((n)*sizeof(t)))

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P6_Merge2SLLsSpec
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

		struct Node* newNode(int data) {
			struct Node *node1 = NEW(1, struct Node);
			node1->data = data;
			node1->next = NULL;
			return node1;
		}
		struct Node* str2LL(char *s) {
			if (s == NULL || *s == 0)
				return NULL;

			struct Node *head, *tail;
			head = newNode(*(s));
			tail = head;
			s++;
			while (*s != '\0') {
				tail->next = newNode(*(s++));
				tail = tail->next;
			}
			return head;
		}
		
		int areEqual(struct Node *head, char *str) {
			if (head == NULL)
				if (strlen(str) == 0)
					return 1;
			if (head != NULL && strlen(str) == 0)
				return 0;

			int i = 0;

			while (str[i] != '\0' && head != NULL)
			{
				if (str[i] != head->data)
					return 0;
				head = head->next;
				i++;
			}
			if (head != NULL || str[i] != '\0')
				return 0;
			return 1;
		}

		[TestMethod]
		void Problem6_Testcase1()
		{
			struct Node *one = str2LL("abc");
			struct Node *two = str2LL("a");

			char expected[] = "aabc";
			struct Node *result = merge(one, two);
			int ans = areEqual(result, expected);
			Assert::AreEqual(1, ans, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem6_Testcase2()
		{
			struct Node *one = str2LL("a");
			struct Node *two = str2LL("a");
			char expected[] = "aa";
			struct Node *result = merge(one, two);
			Assert::AreEqual(1, areEqual(result, expected), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem6_Testcase3()
		{
			struct Node *one = str2LL("aceghikm");
			struct Node *two = str2LL("bdf");
			char expected[] = "abcdefghikm";
			struct Node *result = merge(one, two);
			Assert::AreEqual(1, areEqual(result, expected), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem6_Testcase4()
		{
			struct Node *one = str2LL("123456789");
			struct Node *two = str2LL("123456789");
			char expected[] = "112233445566778899";
			struct Node *result = merge(one, two);
			Assert::AreEqual(1, areEqual(result, expected), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem6_Testcase5()
		{
			struct Node *one = str2LL("abc");
			struct Node *two = str2LL("");
			char expected[] = "abc";
			struct Node *result = merge(one, two);
			Assert::AreEqual(1, areEqual(result, expected), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem6_Testcase6()
		{
			struct Node *one = str2LL("");
			struct Node *two = str2LL("");
			char expected[] = "";
			struct Node *result = merge(one, two);
			Assert::AreEqual(1, areEqual(result, expected), L"Failed for Invalid case P1", 1, 2);
		};
		[TestMethod]
		void Problem6_Testcase7()
		{
			struct Node *one = NULL;
			struct Node *two = str2LL("heya");
			char expected[] = "heya";
			struct Node *result = merge(one, two);
			Assert::AreEqual(1, areEqual(result, expected), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem6_Testcase8()
		{
			struct Node *one = str2LL("heya");
			struct Node *two = NULL;
			char expected[] = "heya";
			struct Node *result = merge(one, two);
			Assert::AreEqual(1, areEqual(result, expected), L"Failed for Invalid case P1", 1, 2);
		};

		bool isNULL(Node *k)
		{
			if (k == NULL)
				return true;
			return false;
		}

		[TestMethod]
		void Problem6_Testcase9()
		{
			struct Node *one = NULL;
			struct Node *two = NULL;
			struct Node *result = merge(one, two);
			Assert::AreEqual(true, isNULL(result), L"Failed for Invalid case P1", 1, 2);
		};
	};
}
