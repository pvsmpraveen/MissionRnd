#include "stdafx.h"
#include "../src/Problem3.cpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Problem3Spec
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

		struct node *createnode(int num)
		{
			struct node *new_node = (struct node*)malloc(sizeof(struct node));
			new_node->num = num;
			new_node->prev = NULL;
			new_node->next = NULL;
			return new_node;
		}

		struct node* strtoDLL(char *str)
		{
			int len = strlen(str);
			if (len == 0)
				return NULL;

			struct node *head = createnode(str[len - 1] - '0');
			for (int i = len - 2; i >= 0; i--)
			{
				struct node *temp = createnode(str[i] - '0');
				head->prev = temp;
				temp->next = head;
				head = temp;
			}

			return head;			
		}

		
		[TestMethod, Timeout(1000)]
		void Sample1_Problem3()
		{
			struct node *passkey = strtoDLL("321");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(1, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample2_Problem3()
		{
			struct node *passkey = strtoDLL("758");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(4, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample3_Problem3()
		{
			struct node *passkey = strtoDLL("");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(NULL, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec1_Problem3()
		{
			struct node *passkey = strtoDLL("54321");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(1, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec2_Problem3()
		{
			struct node *passkey = strtoDLL("54312");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(2, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec3_Problem3()
		{
			struct node *passkey = strtoDLL("54231");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(3, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec4_Problem3()
		{
			struct node *passkey = strtoDLL("12345");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(120, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec5_Problem3()
		{
			struct node *passkey = strtoDLL("15324");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(100, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec6_Problem3()
		{
			struct node *passkey = strtoDLL("35412");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(50, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec7_Problem3()
		{
			struct node *passkey = strtoDLL("0123456789");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(3628800, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec8_Problem3()
		{
			// Generated and verified by python 
			struct node *passkey = strtoDLL("9064317285");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(335267, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec9_Problem3()
		{
			// Generated and verified by python 
			struct node *passkey = strtoDLL("9876543210");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(1, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec10_Problem3()
		{
			// Generated and verified by python 
			struct node *passkey = strtoDLL("12");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(2, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec11_Problem3()
		{
			struct node *passkey = strtoDLL("54321");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(1, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec12_Problem3()
		{
			struct node *passkey = strtoDLL("54312");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(2, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec13_Problem3()
		{
			struct node *passkey = strtoDLL("54231");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(3, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec14_Problem3()
		{
			struct node *passkey = strtoDLL("12345");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(120, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec15_Problem3()
		{
			struct node *passkey = strtoDLL("15324");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(100, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec16_Problem3()
		{
			struct node *passkey = strtoDLL("35412");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(50, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec17_Problem3()
		{
			struct node *passkey = strtoDLL("0123456789");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(3628800, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec18_Problem3()
		{
			// Generated and verified by python 
			struct node *passkey = strtoDLL("9064317285");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(335267, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec19_Problem3()
		{
			// Generated and verified by python 
			struct node *passkey = strtoDLL("9876543210");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(1, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec20_Problem3()
		{
			// Generated and verified by python 
			struct node *passkey = strtoDLL("12");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(2, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec21_Problem3()
		{
			struct node *passkey = strtoDLL("331212211");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(20, actualAns, L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec22_Problem3()
		{
			// Generated and verified by python 
			struct node *passkey = strtoDLL("322211113");
			int actualAns = doorstoCross(passkey);
			Assert::AreEqual(60, actualAns, L"Failed  ", 1, 2);
		};


		
	};
}
