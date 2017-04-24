#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/Concat4Strings.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(Concat4StringsSpec)
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

		TEST_METHOD(Sample1_Concat4Strings)
		{

			char *res = concat_4strings(NULL, NULL, NULL, NULL);
			int check = 0;
			if (res == NULL){
				check = 1;
			}
			Assert::AreEqual(1, check, L"Null case failed for Concat 4 Strings");
		};


		TEST_METHOD(Sample2_Concat4Strings)
		{
			char str[4][100] = { "bd", "ab", "fg", "yz" };
			char ans[10] = "abdfgyz";
			char *res = concat_4strings(str[0], str[1], str[2], str[3]);
			int check = 0;
			check = strcmp(res, ans);
			Assert::AreEqual(0, check, L"Null case failed for Concat 4 Strings");
		};


		//Real Test Cases


		TEST_METHOD(Real_Concat4Strings1)
		{
			char str[4][100] = { "acat", "tiger", "silica", "licaria" };
			char ans[100] = "silicariacatiger";
			char *res = concat_4strings(str[0], str[1], str[2], str[3]);
			int check = 0;
			check = strcmp(res, ans);
			Assert::AreEqual(0, check, L"Real case failed for Concat 4 Strings");
		};


		TEST_METHOD(Real_Concat4Strings2)
		{
			char str[4][100] = { "abcde", "bcde", "bcdef", "gh" };
			char ans[100] = "abcdefgh";
			char *res = concat_4strings(str[0], str[1], str[2], str[3]);
			int check = 0;
			check = strcmp(res, ans);
			Assert::AreEqual(0, check, L"Real case failed for Concat 4 Strings");
		};


		TEST_METHOD(Real_Concat4Strings3)
		{
			char str[4][100] = { "abcde", "bcde", "bcdef", "gh" };
			char ans[100] = "abcdefgh";
			char *res = concat_4strings(str[0], str[1], str[2], str[3]);
			int check = 0;
			check = strcmp(res, ans);
			Assert::AreEqual(0, check, L"Real case failed for Concat 4 Strings");
		};


		TEST_METHOD(Real_Concat4Strings4)
		{
			char str[4][100] = { "abcde", "bcde", "bcdef", "gh" };
			char ans[100] = "abcdefgh";
			char *res = concat_4strings(str[0], str[1], str[2], str[3]);
			int check = 0;
			check = strcmp(res, ans);
			Assert::AreEqual(0, check, L"Real case failed for Concat 4 Strings");
		};


		TEST_METHOD(Real_Concat4Strings5)
		{
			char st[4][100] = { "gh", "bcdef", "bcde", "abcde" };
			char ans1[100] = "abcdefgh";
			char *res1 = concat_4strings(st[0], st[1], st[2], st[3]);
			int check = 0;
			check = strcmp(res1, ans1);
			Assert::AreEqual(0, check, L"Null case failed for Concat 4 Strings");
		};


		TEST_METHOD(Real_Concat4Strings6)
		{
			char st[4][100] = { "kk", "kkkkkk", "k", "k" };
			char ans1[100] = "kkkkkk";
			char *res1 = concat_4strings(st[0], st[1], st[2], st[3]);
			int check = 0;
			check = strcmp(res1, ans1);
			Assert::AreEqual(0, check, L"Real case failed for Concat 4 Strings");
		};

		TEST_METHOD(Real_Concat4Strings7)
		{
			char st[4][100] = { "kk", "kkkkkk", "k", "k" };
			char ans1[100] = "kkkkkk";
			char *res1 = concat_4strings(st[0], st[1], st[2], st[3]);
			int check = 0;
			check = strcmp(res1, ans1);
			Assert::AreEqual(0, check, L"Real case failed for Concat 4 Strings");
		};

		TEST_METHOD(Real_Concat4Strings8)
		{
			char st[4][100] = { "test", "testmetho", "met", "ho" };
			char ans1[100] = "testmetho";
			char *res1 = concat_4strings(st[0], st[1], st[2], st[3]);
			int check = 0;
			check = strcmp(res1, ans1);
			Assert::AreEqual(0, check, L"Real case failed for Concat 4 Strings");
		};

		TEST_METHOD(Real_Concat4Strings9)
		{
			char st[4][100] = { "acat", "catcat", "dogcat", "catcow" };
			char ans1[100] = "acatcatcowdogcat";
			char *res1 = concat_4strings(st[0], st[1], st[2], st[3]);
			int check = 0;
			check = strcmp(res1, ans1);
			Assert::AreEqual(0, check, L"Real case failed for Concat 4 Strings");
		};

		TEST_METHOD(Real_Concat4Strings10)
		{
			char st[4][100] = { "acat", "catca", "dogcat", "catcow" };
			char ans1[100] = "dogcatcacatcow";
			char *res1 = concat_4strings(st[0], st[1], st[2], st[3]);
			int check = 0;
			check = strcmp(res1, ans1);
			Assert::AreEqual(0, check, L"Real case failed for Concat 4 Strings");
		};

		TEST_METHOD(Real_Concat4Strings11)
		{
			char st[4][100] = { "acat", "catca", "dogcat", "catcow" };
			char ans1[100] = "dogcatcacatcow";
			char *res1 = concat_4strings(st[0], st[1], st[2], st[3]);
			int check = 0;
			check = strcmp(res1, ans1);
			Assert::AreEqual(0, check, L"Real case failed for Concat 4 Strings");
		};

		TEST_METHOD(Real_Concat4Strings12)
		{
			char st[4][100] = { "acat", "catca", "dogcat", "catcow" };
			char ans1[100] = "dogcatcacatcow";
			char *res1 = concat_4strings(st[0], st[1], st[2], st[3]);
			int check = 0;
			check = strcmp(res1, ans1);
			Assert::AreEqual(0, check, L"Real case failed for Concat 4 Strings");
		};

		TEST_METHOD(Real_Concat4Strings13)
		{
			char st[4][100] = { "aaaabbbb", "bbbbbc", "c", "dddaaaax" };
			char ans1[100] = "aaaabbbbbcdddaaaax";
			char *res1 = concat_4strings(st[0], st[1], st[2], st[3]);
			int check = 0;
			check = strcmp(res1, ans1);
			Assert::AreEqual(0, check, L"Real case failed for Concat 4 Strings");
			int len = strlen(ans1);
			Assert::AreEqual(18, len, L"Real case failed for Concat 4 Strings");
		};

	};
}