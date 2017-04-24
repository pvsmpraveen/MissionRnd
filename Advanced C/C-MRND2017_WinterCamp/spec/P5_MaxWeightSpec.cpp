#include "stdafx.h"
#include "../src/P5_MaxWeight.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P5_MaxWeightSpec
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

		[TestMethod, Timeout(1000)]
		void Problem5_Testcase1()
		{
			int actualAns;
			char *strings[3] = { { "age" },
			{ "get" },
			{ "tap" }
			};
			actualAns = maxWeight(strings, 3);
			Assert::AreEqual(34, actualAns, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Problem5_Testcase2()
		{
			int actualAns;
			char *strings[3] = {
				{ "aaa" },
				{ "bbb" },
				{ "cc" }
			};
			actualAns = maxWeight(strings, 3);

			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
		};
		[TestMethod, Timeout(1000)]
		void Problem5_Testcase3()
		{
			int actualAns;
			char *strings[3] = {
				{ "\0" },
				{ "\0" },
				{ "\0" }
			};
			actualAns = maxWeight(strings, 3);

			Assert::AreEqual(0, actualAns, L"Failed for Invalid case P1", 1, 2);
		};
	};
}


