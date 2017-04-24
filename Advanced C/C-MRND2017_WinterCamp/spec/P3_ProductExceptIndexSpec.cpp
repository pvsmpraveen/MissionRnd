#include "stdafx.h"
#include "../src/P3_ProductExceptIndex.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P3_ProductExceptIndexSpec
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
		void Problem3_Testcase1()
		{
			int arr[1] = { 100 }, *res;
			res = productExceptIndex(arr, 1);

			Assert::AreEqual(0, res[0], L"Failed for array size 1", 1, 2);
		};


		[TestMethod, Timeout(1000)]
		void Problem3_Testcase2()
		{
			int arr[2] = { 100, 200 }, *res;
			res = productExceptIndex(arr, 2);

			Assert::AreEqual(200, res[0], L"Failed for array size 1", 1, 2);
			Assert::AreEqual(100, res[1], L"Failed for array size 1", 1, 2);

		};



		[TestMethod, Timeout(1000)]
		void Problem3_Testcase3()
		{
			int arr[5] = { 1, 2, 3, 4, 0 }, *res;
			res = productExceptIndex(arr, 5);

			Assert::AreEqual(0, res[0], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, res[1], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, res[2], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, res[3], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(24, res[4], L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Problem3_Testcase4()
		{
			int arr[6] = { 1, 2, 0, 3, 4, 0 }, *res;
			res = productExceptIndex(arr, 6);

			Assert::AreEqual(0, res[0], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, res[1], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, res[2], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, res[3], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, res[4], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, res[5], L"Failed for Invalid case P1", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void Problem3_Testcase5()
		{
			int arr[4] = { 5, 4, 3, 6 }, *res;
			res = productExceptIndex(arr, 4);

			Assert::AreEqual(72, res[0], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(90, res[1], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(120, res[2], L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(60, res[3], L"Failed for Invalid case P1", 1, 2);

		};
	};
}
