#include "stdafx.h"
#include "../src/Problem2.cpp"

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
		void Sample_Problem2()
		{
			int res = isSTRMatched(NULL, NULL);
			if (res == 0){
				Assert::Fail("Failed for null case in p2");
			}
		};
		[TestMethod, Timeout(1000)]
		void Sample2_Problem2()
		{
			char s1[100] = "a4e";
			char s2[100] = "4e";
			int expectedAns = 0;
			int actualAns = isSTRMatched(s1,s2);
			Assert::AreEqual(expectedAns, actualAns, L"Failed  ", 1, 2);
			
		};
		[TestMethod, Timeout(1000)]
		void Sample3_Problem2()
		{
			char s1[100] = "a3e2";
			char s2[100] = "4ekl";
			int expectedAns = 1;
			int actualAns = isSTRMatched(s1, s2);
			Assert::AreEqual(expectedAns, actualAns, L"Failed  ", 1, 2);
		};


		//Real Cases

		void testSimpleCaseP1(char *s1, char *s2, int expectedAns){
			int actualAns = isSTRMatched(s1, s2);
			Assert::AreEqual(expectedAns, actualAns, L"Failed  ", 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void Real1_Problem2()
		{
			testSimpleCaseP1("", "", 1);
			testSimpleCaseP1("", "e", 0);
		};
		[TestMethod, Timeout(1000)]
		void Real2_Problem2()
		{
			testSimpleCaseP1("", "", 1);
			testSimpleCaseP1("", "e", 0);
		};
		[TestMethod, Timeout(1000)]
		void Real3_Problem2()
		{
			testSimpleCaseP1("", "", 1);
			testSimpleCaseP1("", "e", 0);
		};

		[TestMethod, Timeout(1000)]
		void Real4_Problem2()
		{
			
			testSimpleCaseP1("abc3", "e", 0);
			testSimpleCaseP1("abc2d", "abc3", 1);
		};

		[TestMethod, Timeout(1000)]
		void Real5_Problem2()
		{
			
			testSimpleCaseP1("abc3", "e", 0);
			testSimpleCaseP1("abc2d", "abc3", 1);
		};

		[TestMethod, Timeout(1000)]
		void Real6_Problem2()
		{
			testSimpleCaseP1("1bc2d1", "2c4", 1);
			testSimpleCaseP1("1bc4", "ebcabcd", 1);
			testSimpleCaseP1("abc3", "e", 0);
		};

		[TestMethod, Timeout(1000)]
		void Real7_Problem2()
		{
			testSimpleCaseP1("1bc2d1", "2c4", 1);
			testSimpleCaseP1("1bc4", "ebcabcd", 1);
			testSimpleCaseP1("abc3", "e", 0);
		};

		[TestMethod, Timeout(1000)]
		void Real8_Problem2()
		{
			testSimpleCaseP1("b4e6dz1", "3zzza3bbdzk", 0);
			testSimpleCaseP1("b4e6dz1", "3zzea3bbdzk", 1);
			//testSimpleCaseP1("1bc4", "ebcabcd", 1);
		};


		[TestMethod, Timeout(1000)]
		void Real9_Problem2()
		{
			testSimpleCaseP1("b4e6dz1", "3zzza3bbdzk", 0);
			testSimpleCaseP1("b4e6dz1", "3zzea3bbdzk", 1);
			//testSimpleCaseP1("1bc4", "ebcabcd", 1);
		};
		[TestMethod, Timeout(1000)]
		void Real10_Problem2()
		{
			testSimpleCaseP1("b4e6dz1", "3zzza3bbdzk", 0);
			testSimpleCaseP1("b4e6dz1", "3zzea3bbdzk", 1);
			//testSimpleCaseP1("1bc4", "ebcabcd", 1);
		};

		[TestMethod, Timeout(1000)]
		void Real11_Problem2()
		{
			testSimpleCaseP1("b4e6dz1b4e6dz1", "3zzza3bbdzk3zzza3bbdzk", 0);
			testSimpleCaseP1("aaaaaa", "1aaaa1", 1);
			//testSimpleCaseP1("1bc4", "ebcabcd", 1);
		};

		[TestMethod, Timeout(1000)]
		void Real12_Problem2()
		{
			testSimpleCaseP1("a1b1b1b1", "bbbbbbbb", 0);
			testSimpleCaseP1("a1b1b1b1", "abbbbbbb", 1);
			//testSimpleCaseP1("1bc4", "ebcabcd", 1);
		};

		[TestMethod, Timeout(1000)]
		void Real13_Problem2()
		{
			testSimpleCaseP1("a1b1b1b1", "bbbbbbbb", 0);
			testSimpleCaseP1("a1b1b1b1", "abbbbbbb", 1);
			testSimpleCaseP1("1bc4", "ebcabcd", 1);
			testSimpleCaseP1("a1b1b1b1", "bbbbbbbb", 0);
			testSimpleCaseP1("a1b1b1b1", "abbbbbbb", 1);
			testSimpleCaseP1("b4e6dz1b4e6dz1", "3zzza3bbdzk3zzza3bbdzk", 0);
			testSimpleCaseP1("aaaaaa", "1aaaa1", 1);
		};
		//2Digit test cases - 8 

		[TestMethod, Timeout(1000)]
		void Real14_Problem2()
		{
			testSimpleCaseP1("10", "9a", 1);
			testSimpleCaseP1("10", "11", 0);
		
		};

		[TestMethod, Timeout(1000)]
		void Real15_Problem2()
		{
			testSimpleCaseP1("10", "9a", 1);
			testSimpleCaseP1("10", "11", 0);

		};

		[TestMethod, Timeout(1000)]
		void Real16_Problem2()
		{
			testSimpleCaseP1("10a10", "9aa9b", 1);
			testSimpleCaseP1("a10a10", "99", 0);

		};
		[TestMethod, Timeout(1000)]
		void Real17_Problem2()
		{
			testSimpleCaseP1("10a10", "9aa9b", 1);
			testSimpleCaseP1("a10a10", "99", 0);

		};

		[TestMethod, Timeout(1000)]
		void Real18_Problem2()
		{
			testSimpleCaseP1("123a435", "124a434", 1);
			testSimpleCaseP1("123a435", "124a435", 0);

		};
		[TestMethod, Timeout(1000)]
		void Real19_Problem2()
		{
			testSimpleCaseP1("123a435", "124a434", 1);
			testSimpleCaseP1("123a435", "124a435", 0);

		};
		[TestMethod, Timeout(1000)]
		void Real20_Problem2()
		{
			testSimpleCaseP1("123a435", "124a434", 1);
			testSimpleCaseP1("123a435", "124a435", 0);

		};
		[TestMethod, Timeout(1000)]
		void Real21_Problem2()
		{
			testSimpleCaseP1("123a435", "124a434", 1);
			testSimpleCaseP1("123a435", "124a435", 0);

		};

		[TestMethod, Timeout(1000)]
		void Real22_Problem2()
		{
			testSimpleCaseP1("100", "100", 1);
			testSimpleCaseP1("1", "124a435", 0);

		};
	};
}
