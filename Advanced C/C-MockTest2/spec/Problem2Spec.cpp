#include "stdafx.h"
#include "../src/Problem2.cpp"
#include <stdio.h>
#include <stdlib.h>


using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class Problem2Spec
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
		void Sample1_Problem2()
		{
			int **arr = (int**)calloc(2, sizeof(int*));
			for (int i = 0; i < 2; i++)
			{
				arr[i] = (int*)calloc(2, sizeof(int));
				for (int j = 0; j < 2; j++)
					arr[i][j] = i*2 + j + 1;
			}

			rotateArray(arr, 2, "LRR");
			Assert::AreEqual(3, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[1][1], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample2_Problem2()
		{
			int **arr = (int**)calloc(1, sizeof(int*));

			arr[0] = (int*)calloc(1, sizeof(int));
			arr[0][0] = 1;
			rotateArray(arr, 1, "llllLLLLLRRRRRRRRRrrrrrrrrrr");
			Assert::AreEqual(1, arr[0][0], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample3_Problem2()
		{
			int **arr = (int**)calloc(2, sizeof(int*));
			for (int i = 0; i < 2; i++)
			{
				arr[i] = (int*)calloc(2, sizeof(int));
				for (int j = 0; j < 2; j++)
					arr[i][j] = i * 2 + j + 1;
			}

			rotateArray(arr, 2, "L");
			Assert::AreEqual(2, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[1][1], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec1_Problem2()
		{
			int **arr = (int**)calloc(2, sizeof(int*));
			for (int i = 0; i < 2; i++)
			{
				arr[i] = (int*)calloc(2, sizeof(int));
				for (int j = 0; j < 2; j++)
					arr[i][j] = i * 2 + j + 1;
			}

			rotateArray(arr, 2, "LRRR");
			Assert::AreEqual(4, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[1][1], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec2_Problem2()
		{
			int **arr = (int**)calloc(2, sizeof(int*));
			for (int i = 0; i < 2; i++)
			{
				arr[i] = (int*)calloc(2, sizeof(int));
				for (int j = 0; j < 2; j++)
					arr[i][j] = i * 2 + j + 1;
			}

			rotateArray(arr, 2, "LRRRLRR");
			Assert::AreEqual(2, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[1][1], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec3_Problem2()
		{
			int **arr = (int**)calloc(2, sizeof(int*));
			for (int i = 0; i < 2; i++)
			{
				arr[i] = (int*)calloc(2, sizeof(int));
				for (int j = 0; j < 2; j++)
					arr[i][j] = i * 2 + j + 1;
			}

			rotateArray(arr, 2, "LRRRrr");
			Assert::AreEqual(1, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[1][1], L"Failed  ", 1, 2);
			rotateArray(arr, 2, "LRRRLRR");
			Assert::AreEqual(2, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[1][1], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec4_Problem2()
		{
			int len = 3;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "lrlrlr");
			Assert::AreEqual(1, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(7, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(9, arr[2][2], L"Failed  ", 1, 2);
			rotateArray(arr, len, "lrlrl");
			Assert::AreEqual(3, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(9, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(7, arr[2][2], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec5_Problem2()
		{
			int len = 3;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "lrlrl");
			Assert::AreEqual(3, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(9, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(7, arr[2][2], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec6_Problem2()
		{
			int len = 3;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "lrlrlrll");
			Assert::AreEqual(9, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(7, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[2][2], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec7_Problem2()
		{
			int len = 3;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "lrlrlrlll");
			Assert::AreEqual(7, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(9, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[2][2], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec8_Problem2()
		{
			int len = 3;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "rlrlrlr");
			Assert::AreEqual(7, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(9, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[2][2], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec9_Problem2()
		{
			int len = 200;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "rLLrLLrLLrLLrLLrLLrLLrLLrLLrLLllRllRllRllRllRllRllRllRllRllRr");

			for (int i = 0, b = 0; i < len; i++, b++)
				for (int j = 0, a = len - 1; j < len; j++, a--)
					Assert::AreEqual(a*len + b + 1, arr[i][j], L"Failed  ", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void HidedSpec10_Problem2()
		{
			int len = 200;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "rLLrLLrLLrLLrLLrLLrLLrLLrLLrLLllRllRllRllRllRllRllRllRllRllRr");

			for (int i = 0, b = 0; i < len; i++, b++)
				for (int j = 0, a = len - 1; j < len; j++, a--)
					Assert::AreEqual(a*len + b + 1, arr[i][j], L"Failed  ", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void HidedSpec11_Problem2()
		{
			int len = 250;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "rLLrLLrLLrLLrLLrLLrLLrLLrLLrLLllRllRllRllRllRllRllRllRllRllRr");

			for (int i = 0, b = 0; i < len; i++, b++)
				for (int j = 0, a = len - 1; j < len; j++, a--)
					Assert::AreEqual(a*len + b + 1, arr[i][j], L"Failed  ", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void HidedSpec12_Problem2()
		{
			int len = 200;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "rLLrLLrLLrLLrLLrLLrLLrLLrLLrLLllRllRllRllRllRllRllRllRllRllRr");

			for (int i = 0, b = 0; i < len; i++, b++)
				for (int j = 0, a = len - 1; j < len; j++, a--)
					Assert::AreEqual(a*len + b + 1, arr[i][j], L"Failed  ", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void HidedSpec13_Problem2()
		{
			int **arr = (int**)calloc(2, sizeof(int*));
			for (int i = 0; i < 2; i++)
			{
				arr[i] = (int*)calloc(2, sizeof(int));
				for (int j = 0; j < 2; j++)
					arr[i][j] = i * 2 + j + 1;
			}

			rotateArray(arr, 2, "LRRRrr");
			Assert::AreEqual(1, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[1][1], L"Failed  ", 1, 2);
			rotateArray(arr, 2, "LRRRLRR");
			Assert::AreEqual(2, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[1][1], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec14_Problem2()
		{
			int len = 3;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "lrlrlr");
			Assert::AreEqual(1, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(7, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(9, arr[2][2], L"Failed  ", 1, 2);
			rotateArray(arr, len, "lrlrl");
			Assert::AreEqual(3, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(9, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(7, arr[2][2], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec15_Problem2()
		{
			int len = 3;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "lrlrl");
			Assert::AreEqual(3, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(9, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(7, arr[2][2], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec16_Problem2()
		{
			int len = 3;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "lrlrlrll");
			Assert::AreEqual(9, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(7, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[2][2], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec17_Problem2()
		{
			int len = 3;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "lrlrlrlll");
			Assert::AreEqual(7, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(9, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[2][2], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec18_Problem2()
		{
			int len = 3;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "rlrlrlr");
			Assert::AreEqual(7, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(9, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[2][2], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec19_Problem2()
		{
			int len = 3;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "rlrlrr");
			Assert::AreEqual(9, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(7, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(3, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[2][2], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec20_Problem2()
		{
			int len = 200;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "rLLrLLrLLrLLrLLrLLrLLrLLrLLrLLllRllRllRllRllRllRllRllRllRllRr");

			for (int i = 0, b = 0; i < len; i++, b++)
				for (int j = 0, a = len - 1; j < len; j++, a--)
					Assert::AreEqual(a*len + b + 1, arr[i][j], L"Failed  ", 1, 2);

		};

		[TestMethod, Timeout(1000)]
		void HidedSpec21_Problem2()
		{
			int len = 3;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "rrrlrlrlr");
			Assert::AreEqual(3, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(9, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(7, arr[2][2], L"Failed  ", 1, 2);
		};

		[TestMethod, Timeout(1000)]
		void HidedSpec22_Problem2()
		{
			int len = 3;
			int **arr = (int**)calloc(len, sizeof(int*));
			for (int i = 0; i < len; i++)
			{
				arr[i] = (int*)calloc(len, sizeof(int));
				for (int j = 0; j < len; j++)
					arr[i][j] = i * len + j + 1;
			}

			rotateArray(arr, len, "rrrlrlrlr");
			Assert::AreEqual(3, arr[0][0], L"Failed  ", 1, 2);
			Assert::AreEqual(6, arr[0][1], L"Failed  ", 1, 2);
			Assert::AreEqual(9, arr[0][2], L"Failed  ", 1, 2);
			Assert::AreEqual(2, arr[1][0], L"Failed  ", 1, 2);
			Assert::AreEqual(5, arr[1][1], L"Failed  ", 1, 2);
			Assert::AreEqual(8, arr[1][2], L"Failed  ", 1, 2);
			Assert::AreEqual(1, arr[2][0], L"Failed  ", 1, 2);
			Assert::AreEqual(4, arr[2][1], L"Failed  ", 1, 2);
			Assert::AreEqual(7, arr[2][2], L"Failed  ", 1, 2);
		};



	};
}
