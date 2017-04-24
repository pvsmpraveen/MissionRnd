#include "stdafx.h"
#include "../src/P2_TwoSubArraySort.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P2_TwoSubArraySortSpec
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
		void Problem2_Testcase1()
		{
			int arr[5] = { 1, 10, 100, 1000, 10000 };
			twoSubArraySort(arr, 5);
			Assert::AreEqual(1, arr[0], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(10, arr[1], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(100, arr[2], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1000, arr[3], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(10000, arr[4], L"Failed for Invalid case P1", 1, 2);


		};

		[TestMethod, Timeout(1000)]
		void Problem2_Testcase2()
		{
			int arr[1] = { 199 };
			twoSubArraySort(arr, 1);
			Assert::AreEqual(199, arr[0], L"Failed for value at index 0", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Problem2_Testcase3()
		{
			int arr[2] = { 2, 1 };
			twoSubArraySort(arr, 2);
			Assert::AreEqual(1, arr[0], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(2, arr[1], L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Problem2_Testcase4()
		{
			int arr[6] = { 2, 3, 4, 5, 6, 1 };
			twoSubArraySort(arr, 6);
			Assert::AreEqual(1, arr[0], L"Failed for Value at index 0", 1, 2);
			Assert::AreEqual(2, arr[1], L"Failed for Value at index 1", 1, 2);
			Assert::AreEqual(3, arr[2], L"Failed for Value at index 2", 1, 2);
			Assert::AreEqual(4, arr[3], L"Failed for Value at index 3", 1, 2);
			Assert::AreEqual(5, arr[4], L"Failed for Value at index 4", 1, 2);
			Assert::AreEqual(6, arr[5], L"Failed for Value at index 5", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void Problem2_Testcase5()
		{
			int arr[6] = { 7, 2, 3, 4, 5, 6 };
			twoSubArraySort(arr, 6);
			Assert::AreEqual(2, arr[0], L"Failed for Value at index 0", 1, 2);
			Assert::AreEqual(3, arr[1], L"Failed for Value at index 1", 1, 2);
			Assert::AreEqual(4, arr[2], L"Failed for Value at index 2", 1, 2);
			Assert::AreEqual(5, arr[3], L"Failed for Value at index 3", 1, 2);
			Assert::AreEqual(6, arr[4], L"Failed for Value at index 4", 1, 2);
			Assert::AreEqual(7, arr[5], L"Failed for Value at index 5", 1, 2);

		};


		[TestMethod, Timeout(1000)]
		void Problem2_Testcase6()
		{
			int arr[11] = { 2, 3, 4, 5, 6, 7, 101, 9, 11, 100, 1000 };
			twoSubArraySort(arr, 11);
			Assert::AreEqual(2, arr[0], L"Failed for value at index 0", 1, 2);
			Assert::AreEqual(3, arr[1], L"Failed for value at index 1", 1, 2);
			Assert::AreEqual(4, arr[2], L"Failed for value at index 2", 1, 2);
			Assert::AreEqual(5, arr[3], L"Failed for value at index 3", 1, 2);
			Assert::AreEqual(6, arr[4], L"Failed for value at index 4", 1, 2);
			Assert::AreEqual(7, arr[5], L"Failed for value at index 5", 1, 2);
			Assert::AreEqual(9, arr[6], L"Failed for value at index 6", 1, 2);
			Assert::AreEqual(11, arr[7], L"Failed for value at index 7", 1, 2);
			Assert::AreEqual(100, arr[8], L"Failed for value at index 8", 1, 2);
			Assert::AreEqual(101, arr[9], L"Failed for value at index 9", 1, 2);
			Assert::AreEqual(1000, arr[10], L"Failed for value at index 10", 1, 2);
		};

	};
}
