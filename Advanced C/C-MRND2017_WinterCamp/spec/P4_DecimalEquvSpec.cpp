#include "stdafx.h"
#include "../src/P4_DecimalEquv.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P4_DecimalEquvSpec
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
		void Problem4_Testcase1()
		{
			int **matrix, row_index;
			matrix = (int **)malloc(sizeof(int*) * 4);

			for (row_index = 0; row_index < 4; row_index++)
				matrix[row_index] = (int *)malloc(sizeof(int) * 4);

			matrix[0][0] = 0;
			matrix[0][1] = 0;
			matrix[0][2] = 0;
			matrix[0][3] = 0;

			matrix[1][0] = 0;
			matrix[1][1] = 0;
			matrix[1][2] = 0;
			matrix[1][3] = 0;

			matrix[2][0] = 0;
			matrix[2][1] = 0;
			matrix[2][2] = 0;
			matrix[2][3] = 0;

			matrix[3][0] = 0;
			matrix[3][1] = 0;
			matrix[3][2] = 0;
			matrix[3][3] = 0;

			int res_row, res_col;
			highestDec(matrix, 4, &res_row, &res_col);
			Assert::AreEqual(1, res_row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, res_col, L"Failed for Invalid case P1", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void Problem4_Testcase2()
		{

			int **matrix, row_index;
			matrix = (int **)malloc(sizeof(int*) * 4);

			for (row_index = 0; row_index < 4; row_index++)
				matrix[row_index] = (int *)malloc(sizeof(int) * 4);

			matrix[0][0] = 1;
			matrix[0][1] = 1;
			matrix[0][2] = 1;
			matrix[0][3] = 1;

			matrix[1][0] = 1;
			matrix[1][1] = 1;
			matrix[1][2] = 1;
			matrix[1][3] = 1;

			matrix[2][0] = 1;
			matrix[2][1] = 1;
			matrix[2][2] = 1;
			matrix[2][3] = 1;

			matrix[3][0] = 1;
			matrix[3][1] = 1;
			matrix[3][2] = 1;
			matrix[3][3] = 1;

			int res_row, res_col;
			highestDec(matrix, 4, &res_row, &res_col);
			Assert::AreEqual(1, res_row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, res_col, L"Failed for Invalid case P1", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void Problem4_Testcase3()
		{

			int **matrix, row_index;
			matrix = (int **)malloc(sizeof(int*) * 4);

			for (row_index = 0; row_index < 4; row_index++)
				matrix[row_index] = (int *)malloc(sizeof(int) * 4);

			matrix[0][0] = 1;
			matrix[0][1] = 0;
			matrix[0][2] = 1;
			matrix[0][3] = 0;

			matrix[1][0] = 0;
			matrix[1][1] = 1;
			matrix[1][2] = 0;
			matrix[1][3] = 1;

			matrix[2][0] = 1;
			matrix[2][1] = 1;
			matrix[2][2] = 0;
			matrix[2][3] = 0;

			matrix[3][0] = 0;
			matrix[3][1] = 0;
			matrix[3][2] = 1;
			matrix[3][3] = 1;

			int res_row, res_col;
			highestDec(matrix, 4, &res_row, &res_col);
			Assert::AreEqual(3, res_row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, res_col, L"Failed for Invalid case P1", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void Problem4_Testcase4()
		{

			int **matrix, row_index;
			matrix = (int **)malloc(sizeof(int*) * 4);

			for (row_index = 0; row_index < 4; row_index++)
				matrix[row_index] = (int *)malloc(sizeof(int) * 4);

			matrix[0][0] = 1;
			matrix[0][1] = 1;
			matrix[0][2] = 1;
			matrix[0][3] = 0;

			matrix[1][0] = 1;
			matrix[1][1] = 1;
			matrix[1][2] = 0;
			matrix[1][3] = 1;

			matrix[2][0] = 1;
			matrix[2][1] = 0;
			matrix[2][2] = 0;
			matrix[2][3] = 0;

			matrix[3][0] = 0;
			matrix[3][1] = 0;
			matrix[3][2] = 0;
			matrix[3][3] = 1;

			int res_row, res_col;
			highestDec(matrix, 4, &res_row, &res_col);
			Assert::AreEqual(1, res_row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, res_col, L"Failed for Invalid case P1", 1, 2);

		};



		[TestMethod, Timeout(1000)]
		void Problem4_Testcase5()
		{
			int **matrix, row_index;
			matrix = (int **)malloc(sizeof(int*) * 4);

			for (row_index = 0; row_index < 4; row_index++)
				matrix[row_index] = (int *)malloc(sizeof(int) * 4);

			matrix[0][0] = 1;
			matrix[0][1] = 1;
			matrix[0][2] = 1;
			matrix[0][3] = 0;

			matrix[1][0] = 1;
			matrix[1][1] = 1;
			matrix[1][2] = 1;
			matrix[1][3] = 0;

			matrix[2][0] = 1;
			matrix[2][1] = 1;
			matrix[2][2] = 1;
			matrix[2][3] = 0;

			matrix[3][0] = 0;
			matrix[3][1] = 0;
			matrix[3][2] = 0;
			matrix[3][3] = 1;


			int res_row, res_col;
			highestDec(matrix, 4, &res_row, &res_col);
			Assert::AreEqual(1, res_row, L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, res_col, L"Failed for Invalid case P1", 1, 2);

		};

		

	};
}
