#include "stdafx.h"
#include "../src/P12_LargestRectangle.cpp"
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
	public ref class P12_LargestRectangleSpec
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

		[TestMethod]
		void Problem12_Testcase1()
		{
			const int nRows = 2, nCols = 3;
			int map[][nCols] = {{0, 1, 1},
								{0, 1, 1} };
			int row, col, height, width;
			Assert::AreEqual(1, largestRectangle((int*) map, nRows, nCols , &row, &col, &height, &width), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, col, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(2, height, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(2, width, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem12_Testcase2()
		{
			const int nRows = 1, nCols = 2;
			int map[][nCols] = { { 0, 0 } };
			int row, col, height, width;
			Assert::AreEqual(0, largestRectangle((int*)map, nRows, nCols, &row, &col, &height, &width), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, height, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, width, L"Failed for Invalid case P1", 1, 2);
			
		};

		[TestMethod]
		void Problem12_Testcase3()
		{
			Assert::AreEqual(0, largestRectangle(NULL, 5, 5, NULL, NULL, NULL, NULL), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem12_Testcase4()
		{
			const int nRows = 6, nCols = 5;
			int map[][nCols] = {{ 0, 1, 1, 0, 1 },
								{ 0, 1, 1, 0, 0 },
								{ 1, 0, 1, 1, 0 },
								{ 1, 1, 0, 1, 0 },
								{ 1, 1, 1, 1, 0 },
								{ 1, 1, 1, 1, 1 } };
			int row, col, height, width;
			Assert::AreEqual(1, largestRectangle((int*)map, nRows, nCols, &row, &col, &height, &width), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(4, row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, col, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(2, height, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(4, width, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem12_Testcase5()
		{
			const int nRows = 1, nCols = 2;
			int map[][nCols] = { { 0, 1 } };
			int row, height, width;
			Assert::AreEqual(1, largestRectangle((int*)map, nRows, nCols, &row, NULL, &height, &width), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, height, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, width, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem12_Testcase6()
		{
			const int nRows = 1, nCols = 2;
			int map[][nCols] = { { 0, 0 } };
			int row, col, height, width;
			Assert::AreEqual(0, largestRectangle((int*)map, nRows, nCols, &row, &col, &height, &width), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, height, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, width, L"Failed for Invalid case P1", 1, 2);
		};
		[TestMethod]
		void Problem12_Testcase7()
		{
			const int nRows = 4, nCols = 5;
			int map[][nCols] = {{ 0, 1, 1, 0, 1 },
								{ 0, 1, 1, 0, 0 },
								{ 1, 1, 1, 1, 0 },
								{ 1, 1, 1, 1, 1 } };
			int row, col, height;
			Assert::AreEqual(1, largestRectangle((int*)map, nRows, nCols, &row, &col, &height, NULL), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, col, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(4, height, L"Failed for Invalid case P1", 1, 2);
		};
		[TestMethod]
		void Problem12_Testcase8()
		{
			const int nRows = 4, nCols = 5;
			int map[][nCols] = {{ 0, 1, 1, 0, 1 },
								{ 0, 1, 1, 0, 0 },
								{ 1, 1, 1, 1, 0 },
								{ 1, 1, 1, 1, 1 } };
			int row, col, height, width;
			Assert::AreEqual(1, largestRectangle((int*)map, nRows, nCols, &row, &col, &height, &width), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, col, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(4, height, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(2, width, L"Failed for Invalid case P1", 1, 2);
		};
	};
}
