#include "stdafx.h"
#include "../src/P13_LargestSquare.cpp"
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
	public ref class P13_LargestSquareSpec
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
		void Problem13_Testcase1()
		{
			const int nRows = 2, nCols = 3;
			int map[][nCols] = {{0, 1, 1},
								{0, 1, 1} };
			int row, col;
			Assert::AreEqual(2, largestSquare((int*) map, nRows, nCols , &row, &col), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, col, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem13_Testcase2()
		{
			const int nRows = 3, nCols = 3;
			int map[][nCols] = {{ 1, 1, 1 },
								{ 1, 1, 1 },
								{ 0, 1, 0} };
			int row, col;
			Assert::AreEqual(2, largestSquare((int*)map, nRows, nCols, &row, &col), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, col, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem13_Testcase3()
		{
			Assert::AreEqual(-1, largestSquare(NULL, 5, 5, NULL, NULL), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem13_Testcase4()
		{
			const int nRows = 6, nCols = 5;
			int map[][nCols] = {{ 0, 1, 1, 0, 1 },
								{ 0, 1, 1, 0, 0 },
								{ 1, 0, 1, 1, 0 },
								{ 1, 1, 1, 1, 0 },
								{ 1, 1, 1, 1, 0 },
								{ 1, 1, 1, 1, 1 } };
			int row, col;
			Assert::AreEqual(3, largestSquare((int*)map, nRows, nCols, &row, &col), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(3, row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, col, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem13_Testcase5()
		{
			const int nRows = 1, nCols = 2;
			int map[][nCols] = { { 0, 1 } };
			int row;
			Assert::AreEqual(1, largestSquare((int*)map, nRows, nCols, &row, NULL), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, row, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem13_Testcase6()
		{
			const int nRows = 1, nCols = 2;
			int map[][nCols] = { { 0, 0 } };
			int row, col;
			Assert::AreEqual(0, largestSquare((int*)map, nRows, nCols, &row, &col), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem13_Testcase7()
		{
			const int nRows = 4, nCols = 5;
			int map[][nCols] = {{ 0, 1, 1, 1, 1 },
								{ 1, 1, 1, 1, 1 },
								{ 1, 1, 1, 1, 1 },
								{ 1, 1, 1, 1, 1 } };
			int row, col;
			Assert::AreEqual(4, largestSquare((int*)map, nRows, nCols, &row, &col), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, col, L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem13_Testcase8()
		{
			const int nRows = 7, nCols = 5;
			int map[][nCols] = {{ 0, 1, 1, 0, 1 },
								{ 0, 1, 1, 0, 0 },
								{ 1, 1, 1, 1, 1 },
								{ 1, 1, 1, 1, 1 },
								{ 1, 1, 1, 1, 1 },
								{ 1, 1, 1, 1, 1 },
								{ 1, 1, 1, 1, 1 } };
			int row, col;
			Assert::AreEqual(5, largestSquare((int*)map, nRows, nCols, &row, &col), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(2, row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(0, col, L"Failed for Invalid case P1", 1, 2);
		};
	};
}
