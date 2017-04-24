#include "stdafx.h"
#include "../src/P11_GreyCode.cpp"
#include <stdio.h>
#include <stdlib.h>
#define NEW(n, t) ((t*) malloc((n)*sizeof(t)))


using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P11_GreyCodeSpec
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
		int isInCorrectOrder(int *codes, int len) {
			int prev = *codes;
			int xor;
			for (int i = 1; i < len; i++) {
				xor = prev^codes[i];
				if (xor-1 & xor)
					return 0;
				prev = codes[i];
			}
			return 1;
		}
		int hasAllNumbers(int *codes, int len) {
			int upperLimit = len << 1 - 1;
			char *checklist = (char*)calloc(len>8 ? len/8: 1, sizeof(char));
			for (int i = 0; i < len; i++) {
				if (codes[i] < 0 || codes[i] > upperLimit)
					return 0;
				if (checklist[i / 8] & 1 << (i % 8))
					return 0;
				checklist[i / 8] |= 1 << (i % 8);
			}
			return 1;
		}
		int isValidGraysSeq(int *codes, int len) {
			return	isInCorrectOrder(codes, len) &&
					hasAllNumbers(codes, len);
		}
		
		[TestMethod]
		void Problem11_Testcase1()
		{
			const int nBits = 1;
			int codes[1<<nBits];
			Assert::AreEqual(1, makeGrayCodesSeq(codes, nBits), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, isValidGraysSeq(codes, 1<<nBits), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem11_Testcase2()
		{
			const int nBits = 2;
			int codes[1 << nBits];
			Assert::AreEqual(1, makeGrayCodesSeq(codes, nBits), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, isValidGraysSeq(codes, 1 << nBits), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem11_Testcase3()
		{
			const int nBits = 1;
			Assert::AreEqual(0, makeGrayCodesSeq(NULL, nBits), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem11_Testcase4()
		{
			const int nBits = 10;
			int codes[1 << nBits];
			Assert::AreEqual(1, makeGrayCodesSeq(codes, nBits), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, isValidGraysSeq(codes, 1 << nBits), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem11_Testcase5()
		{
			const int nBits = 15;
			int codes[1 << nBits];
			Assert::AreEqual(1, makeGrayCodesSeq(codes, nBits), L"Failed for Invalid case P1", 1, 2);
			Assert::AreEqual(1, isValidGraysSeq(codes, 1 << nBits), L"Failed for Invalid case P1", 1, 2);
		};

		[TestMethod]
		void Problem11_Testcase6()
		{
			int codes[1];
			Assert::AreEqual(0, makeGrayCodesSeq(codes, -1), L"Failed for Invalid case P1", 1, 2);
		};
		
	};
}
