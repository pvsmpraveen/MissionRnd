#include "stdafx.h"
#include "../src/P1_ZerosOnes.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P1_ZerosOnesSpec
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
		void Problem1_Testcase1()
		{
			int array[3] = { 1, 1, 1 };
			sortZerosnOnes(array, 3);
			Assert::AreEqual(1, array[0], L"Failed for value at index 0", 1, 2);
			Assert::AreEqual(1, array[1], L"Failed for value at index 1", 1, 2);
			Assert::AreEqual(1, array[2], L"Failed for value at index 2", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Problem1_Testcase2()
		{
			int array[3] = { 0, 0, 0 };
			sortZerosnOnes(array, 3);
			Assert::AreEqual(0, array[0], L"Failed for value at index 0", 1, 2);
			Assert::AreEqual(0, array[1], L"Failed for value at index 1", 1, 2);
			Assert::AreEqual(0, array[2], L"Failed for value at index 2", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Problem1_Testcase3()
		{
			int array[7] = { 1, 1, 1, 1, 0, 0, 0 };
			sortZerosnOnes(array, 7);
			Assert::AreEqual(0, array[0], L"Failed for value at index 0", 1, 2);
			Assert::AreEqual(0, array[1], L"Failed for value at index 1", 1, 2);
			Assert::AreEqual(0, array[2], L"Failed for value at index 2", 1, 2);
			Assert::AreEqual(1, array[3], L"Failed for value at index 2", 1, 2);
			Assert::AreEqual(1, array[4], L"Failed for value at index 2", 1, 2);
			Assert::AreEqual(1, array[5], L"Failed for value at index 2", 1, 2);
			Assert::AreEqual(1, array[6], L"Failed for value at index 2", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void Problem1_Testcase4()
		{
			int array[2] = { 1, 0 };
			sortZerosnOnes(array, 2);
			Assert::AreEqual(0, array[0], L"Failed for value at index 0", 1, 2);
			Assert::AreEqual(1, array[1], L"Failed for value at index 1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Problem1_Testcase5()
		{
			int array[8] = { 1, 0, 1, 0, 1, 0, 1, 0 };
			sortZerosnOnes(array, 8);
			Assert::AreEqual(0, array[0], L"Failed for value at index 0", 1, 2);
			Assert::AreEqual(0, array[1], L"Failed for value at index 1", 1, 2);
			Assert::AreEqual(0, array[2], L"Failed for value at index 1", 1, 2);
			Assert::AreEqual(0, array[3], L"Failed for value at index 1", 1, 2);
			Assert::AreEqual(1, array[4], L"Failed for value at index 1", 1, 2);
			Assert::AreEqual(1, array[5], L"Failed for value at index 1", 1, 2);
			Assert::AreEqual(1, array[6], L"Failed for value at index 1", 1, 2);
			Assert::AreEqual(1, array[7], L"Failed for value at index 1", 1, 2);

		};

	};
}
