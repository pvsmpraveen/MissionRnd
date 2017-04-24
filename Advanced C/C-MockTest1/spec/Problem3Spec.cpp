#include "stdafx.h"
#include "../src/Problem3.cpp"

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

		void CompareArraysSpec(int *expectedArray, int *actualArray, int len){
			int i = 0;
			for (i = 0; i < len; i++){
				Assert::AreEqual(expectedArray[i], actualArray[i], L"Failed  ", 1, 2);
			}
		}
		[TestMethod ,Timeout(1000)]
		void Sample1_Problem3()
		{
			
			int *actualArray = getLeaderIndex(NULL,-1);
			if (actualArray != NULL){
				Assert::Fail();
			}
		};

		[TestMethod, Timeout(1000)]
		void Sample2_Problem3()
		{
			int arr[100] = { 4, 3, 8, 6, 5, 1, 7, 2 };
			int len = 8;
			int expectedArray[2] = { 6, 3 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};

		[TestMethod, Timeout(1000)]
		void Sample3_Problem3()
		{
			int arr[100] = { 1, 2, 7, 20, 3, 5, 4, 9, 8 };
			int len = 9;
			int expectedArray[2] = { 3, 3 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};

		//Real Test Cases
		[TestMethod,Timeout(1000)]
		void Real_Problem3()
		{

			int arr[100] = { 0, 3, 8, 6, 5, 1, 7, 2 };
			int len = 8;
			int expectedArray[2] = { 6, 3 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real2_Problem3()
		{

			int arr[100] = { 0, 2, 7, 20, 3, 5, 4, 9, 8 };
			int len = 9;
			int expectedArray[2] = { 3, 3 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};


		[TestMethod, Timeout(1000)]
		void Real3_Problem3()
		{

			int arr[100] = { 9,8,7,6,5,4,3,2,1 };
			int len = 9;
			int expectedArray[2] = { 0, 0 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real4_Problem3()
		{

			int arr[100] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			int len = 9;
			int expectedArray[2] = { 0, 0 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real5_Problem3()
		{

			int arr[100] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			int len = 9;
			int expectedArray[2] = { 0, 0 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real6_Problem3()
		{

			int arr[100] = { 1,5,10,15,16,20,25,30,38};
			int len = 9;
			int expectedArray[2] = { 8, 8 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real7_Problem3()
		{

			int arr[100] = { 1, 5, 10, 15, 16, 20, 25, 30, 38 };
			int len = 9;
			int expectedArray[2] = { 8, 8 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real8_Problem3()
		{

			int arr[100] = { 1, 5, 10, 15, 16, 20, 25, 30, 38 };
			int len = 9;
			int expectedArray[2] = { 8, 8 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real9_Problem3()
		{

			int arr[100] = { 1,2400,50,30,20,0,2,4,2304,2300,2000,1800,1000,500,502,504,509,2301,2302,0 };
			int len = 20;
			int expectedArray[2] = { 18, 9 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real10_Problem3()
		{

			int arr[100] = { 1, 2400, 50, 30, 20, 0, 2, 4, 2304, 2300, 2000, 1800, 1000, 500, 502, 504, 509, 2301, 2302, 0 };
			int len = 20;
			int expectedArray[2] = { 18, 9 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};

		[TestMethod, Timeout(1000)]
		void Real11_Problem3()
		{

			int arr[100] = { 1, 2400, 50, 30, 20, 0, 2, 4, 2304, 2300, 2000, 1800, 1000, 500, 502, 504, 509, 2301, 2302, 0 };
			int len = 20;
			int expectedArray[2] = { 18, 9 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};
		[TestMethod, Timeout(1000)]
		void Real12_Problem3()
		{

			int arr[100] = { 1, 2400, 50, 30, 20, 0, 2, 4, 2304, 2300, 2000, 1800, 1000, 500, 502, 504, 509, 2301, 2302, 0 };
			int len = 20;
			int expectedArray[2] = { 18, 9 };
			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedArray, actualArray, 2);
		};

		void runLargeTestCaseP3(){

			int arr[10001] = { 0 };
			int len = 10001;
			int smallArr[10] = {5,10,20,40,55,68,73,84,94,10240};
			int i = 0;
			int totalElems = 0;
			for (i = 0; i < 100; i++){
				int j = 0;
				for (j = 0; j < 10; j++){
					arr[totalElems] = smallArr[j];
					totalElems++;
				}
				smallArr[9] = smallArr[9] - 3;
			}
			arr[10000] = 0;
			int expectedAns[2] = {9,9};
			
			int *actualArray = getLeaderIndex(arr, totalElems);
			CompareArraysSpec(expectedAns, actualArray, 2);
		}

		void runLargeAscTestCaseP3(){
			int arr[100000] = { 0 };
			int len = 100000;
			int i = 0;
			int totalElems = 0;
			for (i = 0; i < len; i++){
				arr[i] = i;
			}

			int expectedAns[2] = { len-1, len-1 };

			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedAns, actualArray, 2);

		}

		void runLargeDescTestCaseP3(){
			int arr[100000] = { 0 };
			int len = 100000;
			int i = 0;
			int totalElems = 0;
			for (i = 0; i < len; i++){
				arr[i] = len-i;
			}

			int expectedAns[2] = { 0,0 };

			int *actualArray = getLeaderIndex(arr, len);
			CompareArraysSpec(expectedAns, actualArray, 2);

		}
		[TestMethod, Timeout(1000)]
		void Real13_Problem3()
		{

			runLargeTestCaseP3();
		};
		[TestMethod, Timeout(1000)]
		void Real16_Problem3()
		{

			runLargeTestCaseP3();
		};
		[TestMethod, Timeout(1000)]
		void Real17_Problem3()
		{

			runLargeTestCaseP3();
		};
		[TestMethod, Timeout(1000)]
		void Real18_Problem3()
		{

			runLargeTestCaseP3();
		};

		[TestMethod, Timeout(1000)]
		void Real19_Problem3()
		{

			runLargeTestCaseP3();
			runLargeTestCaseP3();
			runLargeTestCaseP3();
		};

		[TestMethod, Timeout(1000)]
		void Real20_Problem3()
		{

			runLargeAscTestCaseP3();
			
		};

		[TestMethod, Timeout(1000)]
		void Real21_Problem3()
		{

			runLargeAscTestCaseP3();

		};

		[TestMethod, Timeout(1000)]
		void Real22_Problem3()
		{

			runLargeAscTestCaseP3();
			runLargeAscTestCaseP3();


		};
		[TestMethod, Timeout(1000)]
		void Real23_Problem3()
		{

			runLargeDescTestCaseP3();
			runLargeAscTestCaseP3();


		};
		[TestMethod, Timeout(1000)]
		void Real24_Problem3()
		{

			runLargeAscTestCaseP3();
			runLargeAscTestCaseP3();
			runLargeDescTestCaseP3();
			runLargeDescTestCaseP3();


		};
	};
}
