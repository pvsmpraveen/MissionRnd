#include "stdafx.h"
#include "../src/Problem1.cpp"
#include <string.h>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Problem1Spec
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

		
		void testDefault1_P1()
		{
			int actualAns = isValidEmail("manoj abc@gmail.com");
			Assert::AreEqual(1, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		void testDefault2_P1()
		{
			int actualAns = isValidEmail("manoj iammanoj@gmail.com");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		void testDefault0_P1()
		{
			int actualAns = isValidEmail("abc abc.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample1_Problem1()
		{
			int actualAns = isValidEmail("Manoj iammanoj@gmail.com");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample2_Problem1()
		{
			int actualAns = isValidEmail("abc abc.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample3_Problem1()
		{
			int actualAns = isValidEmail("abcd abc@d.com");
			Assert::AreEqual(1, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec1_Problem1()
		{
			// First character must be alphabet
			int actualAns = isValidEmail("Manoj _manoj@gmail.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec2_Problem1()
		{
			// @ is not allowed
			int actualAns = isValidEmail("Manoj manoj@@gmail.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec3_Problem1()
		{
			// Check of case
			int actualAns = isValidEmail("MANOJ m_mAnOj@gmail.com");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec4_Problem1()
		{
			// prefix check
			int actualAns = isValidEmail("Manoj manojch@gmail.com");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec5_Problem1()
		{
			// sufix check
			int actualAns = isValidEmail("Manoj iammanoj@gmail.com");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec6_Problem1()
		{
			// Length of email check
			int actualAns = isValidEmail("a aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa@gmail.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec7_Problem1()
		{
			// '\' is not allowed 
			int actualAns = isValidEmail("Manoj iamma>noj@gmail.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec8_Problem1()
		{
			// space is not allowed
			int actualAns = isValidEmail("Manoj i am manoj@gmail.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec9_Problem1()
		{
			// .edu, .ac.in , .co.in are also valid
			int actualAns = isValidEmail("Manoj iammanoj@gmail.co.in");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec10_Problem1()
		{
			// two strings check
			int actualAns = isValidEmail("Manoj manoj");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec11_Problem1()
		{
			// single string check
			int actualAns = isValidEmail("Manoj");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec12_Problem1()
		{
			// only valid email  - 1
			int actualAns = isValidEmail("manoj abc_e-fg@gmail.co.in");
			Assert::AreEqual(1, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault2_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec13_Problem1()
		{
			// only valid email  - 2
			int actualAns = isValidEmail("surya    suriii@sun.com      ");
			Assert::AreEqual(1, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault2_P1();
		};


		[TestMethod, Timeout(1000)]
		void HidedSpec14_Problem1()
		{
			// Null check
			int actualAns = isValidEmail("");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec15_Problem1()
		{
			// only valid email  - 2
			int actualAns = isValidEmail("surya    suriii@sun.com      ");
			Assert::AreEqual(1, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault2_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec16_Problem1()
		{
			// only valid email  - 1
			int actualAns = isValidEmail("manoj abc_e-fg@gmail.co.in");
			Assert::AreEqual(1, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault2_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec17_Problem1()
		{
			// Check of case
			int actualAns = isValidEmail("MANOJ m_mAnOj@gmail.com");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec18_Problem1()
		{
			// Check of case
			int actualAns = isValidEmail("MANOJ m_mAnOj@gmail.com");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec19_Problem1()
		{
			// middle instance
			int actualAns = isValidEmail("MAnOJ m_mAnOjabc@gmail.com");
			Assert::AreEqual(1, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault0_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec20_Problem1()
		{
			// .edu, .ac.in , .co.in are also valid
			int actualAns = isValidEmail("Manoj iammanoj@gmail.co.in");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec21_Problem1()
		{
			// .edu, .ac.in , .co.in are also valid
			int actualAns = isValidEmail("Manoj iammanoj@gmail.co.in");
			Assert::AreEqual(2, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault1_P1();
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec22_Problem1()
		{
			// Length of email check
			int actualAns = isValidEmail("a aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa@gmail.com");
			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
			testDefault2_P1();
		};

	};
}
