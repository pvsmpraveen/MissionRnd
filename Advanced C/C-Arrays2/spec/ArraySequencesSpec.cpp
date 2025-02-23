//ArraySequences
#include "stdafx.h"
#include <stdlib.h>
#include "CppUnitTest.h"
#include "./../src/ArraySequences.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(ArraySequencesSpec)
	{
	public:

		int compare_arrays(int *res, int *ans){
			for (int i = 0; i < 6; i++){
				if (res[i] != ans[i]){
					return 0;
				}
			}
			return 1;
		}

		TEST_METHOD(Sample1_ArraySequences)
		{

			int *res = find_sequences(NULL, 0);
			int check = 0;
			if (res == NULL){
				check = 1;
			}
			Assert::AreEqual(1, check, L"Null case failed for Array Sequences");
		};



		TEST_METHOD(Real_ArraySequences1)
		{
			int input[10] = { 1, 100, 199, 5, 10, 15, 30, 60 };
			int ans[6] = { 0, 2, 3, 5, 5, 7 };
			int len = 8;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real Case failed for ArraysSequences");
		};

		TEST_METHOD(Real_ArraySequences2)
		{
			int input[10] = { 15, 30, 60, 1, 100, 199, 5, 10, 15 };
			int ans[6] = { 3, 5, 6, 8, 0, 2 };
			int len = 9;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences");
		};
		TEST_METHOD(Real_ArraySequences3)
		{
			int input[10] = { 15, 30, 60, 1, 100, 199, 5, 10, 15 };
			int ans[6] = { 3, 5, 6, 8, 0, 2 };
			int len = 9;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences");
		};

		TEST_METHOD(Real_ArraySequences4)
		{
			int input[10] = { 15, 30, 60, 1, 50, 99, 100, 101, 102 };
			int ans[6] = { 3, 5, 5, 8, 0, 2 };
			int len = 9;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences");
		};
		TEST_METHOD(Real_ArraySequences5)
		{
			int input[10] = { -20, 10, 40, 160, 200, 240 };
			int ans[6] = { 0, 2, 3, 5, 1, 3 };
			int len = 6;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences");
		};
		TEST_METHOD(Real_ArraySequences6)
		{
			int input[10] = { 1, 5, 9, 13, 17, 29, 41, 53, 106, 212 };
			int ans[6] = { 0, 4, 4, 7, 7, 9 };
			int len = 10;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences");
		};

		TEST_METHOD(Real_ArraySequences7)
		{
			int input[10] = { 1, 5, 9, 13, 53, 106, 212, 200, 188, 176 };
			int ans[6] = { 0, 3, 6, 9, 4, 6 };
			int len = 10;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences");
		};
		TEST_METHOD(Real_ArraySequences8)
		{
			int input[10] = { 1, 5, 9, 13, 53, 106, 212, 200, 188, 176 };
			int ans[6] = { 0, 3, 6, 9, 4, 6 };
			int len = 10;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences");
		};

		TEST_METHOD(Real_ArraySequences9)
		{
			int input[10] = { 10, -10, -30, 10, 20, 40, 10, -20 };
			int ans[6] = { 0, 2, 5, 7, 3, 5 };
			int len = 8;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences");
		};
		TEST_METHOD(Real_ArraySequences10)
		{
			int input[10] = { -2, 10, 22, 48, 74, 148, 296 };
			int ans[6] = { 0, 2, 2, 4, 4, 6 };
			int len = 7;
			int *res = find_sequences(input, len);;
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences");
		};


		TEST_METHOD(Real_ArraySequences11)
		{
			int input[10] = { -10, -30, -50, 100, 50, 25, -100, -225 };
			int ans[6] = { 0, 2, 5, 7, 3, 5 };
			int len = 8;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences");
		};
		TEST_METHOD(Real_ArraySequences12)
		{
			int input[10] = { -9, -5, -1, 3, -9, 27, 30, 33 };
			int ans[6] = { 0, 3, 5, 7, 2, 5 };
			int len = 8;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences");
		};
		TEST_METHOD(Real_ArraySequences13)
		{
			int input[10] = { 12, 1, -10, -21, -43, -65, -87, 1, 5, 25 };
			int ans[6] = { 0, 3, 3, 6, 7, 9 };
			int len = 10;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences");
		}
		TEST_METHOD(Real_ArraySequences14)
		{
			int input[10] = { 12, 0, -12, 0, 6, 12, 20, 10, 5 };
			int ans[6] = { 0, 2, 3, 5, 6, 8 };
			int len = 9;
			int *res = find_sequences(input, len);
			int check = compare_arrays(res, ans);
			Assert::AreEqual(1, check, L"Real2 Case failed for ArraysSequences");
		};

	};
}
