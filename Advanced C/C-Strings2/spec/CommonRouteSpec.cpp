#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/CommonRoute.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(CommonRouteSpec)
	{
	public:


		void testCommonRoute(char *s1, char *s2, int a, int b){
			int i = 0;
			while (s1[i] != '\0'){
				if (s1[i] != s2[i]){
					Assert::AreEqual(1, 2, L"Failed Route");
					return;
				}
				i++;
			}
			Assert::AreEqual(b, a, L"Failed Cost for CommonRoute");
		}
		TEST_METHOD(Sample1_CommonRoute)
		{
			int cost = 0;
			char *res = find_common_route(NULL, NULL, &cost);
			int check = 0;
			if (res == NULL){
				check = 1;
			}
			Assert::AreEqual(1, check, L"Failed sample 1 for CommonRoute");
		};

		TEST_METHOD(Sample2_CommonRoute)
		{
			int cost = -1;
			char hacklist[100] = "CADBZAYZY";
			char codelist[100] = "BZAYACAFRDBZ";
			char ans[100] = "BZAY";
			int cost_ans = 54;
			char *res = NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;
			if (res == NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null");
			}
			testCommonRoute(res, ans, cost, cost_ans);

		};

		int sumof_spec123(char *str){
			int sum = 0;
			int i = 0;
			while (str[i] != NULL){
				sum += str[i] - 64;
				i++;
			}
			return sum;
		}

		TEST_METHOD(Real1_CommonRoute)
		{
			int cost = -1;
			char hacklist[100] = "C";
			char codelist[100] = "CC";
			char ans[100] = "C";
			int cost_ans = 3;
			char *res = NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;
			if (res == NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null");
			}
			testCommonRoute(res, ans, cost, cost_ans);

		};

		TEST_METHOD(Real2_CommonRoute)
		{
			int cost = -1;
			char hacklist[100] = "ABCDEFGHIJK";
			char codelist[100] = "MHIJMMMM";
			char ans[100] = "HIJ";
			int cost_ans = sumof_spec123(ans);
			char *res = NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;
			if (res == NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null");
			}
			testCommonRoute(res, ans, cost, cost_ans);

		};


		TEST_METHOD(Real3_CommonRoute)
		{
			int cost = -1;
			char hacklist[100] = "AMMMMFGHIJK";
			char codelist[100] = "MHIJMMMM";
			char ans[100] = "MMMM";
			int cost_ans = sumof_spec123(ans);
			char *res = NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;
			if (res == NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null");
			}
			testCommonRoute(res, ans, cost, cost_ans);

		};


		TEST_METHOD(Real4_CommonRoute)
		{
			int cost = -1;
			char hacklist[100] = "AMMMMFFFFFHIJK";
			char codelist[100] = "MHIMFFFFF";
			char ans[100] = "MFFFFF";
			int cost_ans = sumof_spec123(ans);
			char *res = NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;
			if (res == NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null");
			}
			testCommonRoute(res, ans, cost, cost_ans);

		};


		TEST_METHOD(Real5_CommonRoute)
		{
			int cost = -1;
			char hacklist[100] = "AAABBBCCCDDDEEEFYZEXTTTT";
			char codelist[100] = "YYYYAAACCCETVEEZEEEFYT";
			char ans[100] = "EEEFY";
			int cost_ans = sumof_spec123(ans);
			char *res = NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;
			if (res == NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null");
			}
			testCommonRoute(res, ans, cost, cost_ans);

		};
		//All Same Letters -2


		TEST_METHOD(Real6_CommonRoute)
		{
			int cost = -1;
			char hacklist[100] = "ZZZZZZZZZZ";
			char codelist[100] = "ZZZZZZZZZ";
			char ans[100] = "ZZZZZZZZZ";
			int cost_ans = sumof_spec123(ans);
			char *res = NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;
			if (res == NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null");
			}
			testCommonRoute(res, ans, cost, cost_ans);

		};


		TEST_METHOD(Real7_CommonRoute)
		{
			int cost = -1;
			char hacklist[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			char codelist[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			char ans[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int cost_ans = sumof_spec123(ans);
			char *res = NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;
			if (res == NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null");
			}
			testCommonRoute(res, ans, cost, cost_ans);

		};

		//Result 0 cases -2 

		TEST_METHOD(Real8_CommonRoute)
		{
			int cost = -1;
			char hacklist[100] = "";
			char codelist[100] = "";
			char *ans = NULL;
			int cost_ans = 0;
			char *res = NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;

			if (res != NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null");
			}
			Assert::AreEqual(0, cost, L"Failed Cost for CommonRoute");
			//testCommonRoute(res, ans, cost, cost_ans);

		};

		TEST_METHOD(Real9_CommonRoute)
		{
			int cost = -1;
			char hacklist[100] = "TTTTTT";
			char codelist[100] = "NNNNN";
			char *ans = NULL;
			int cost_ans = 0;
			char *res = NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;

			if (res != NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null");
			}
			Assert::AreEqual(0, cost, L"Failed Cost for CommonRoute");
			//testCommonRoute(res, ans, cost, cost_ans);

		};

		TEST_METHOD(Real12_CommonRoute)
		{
			int cost = -1;
			char hacklist[100] = "XAABBCCDD";
			char codelist[100] = "XDDZCCUCAB";
			char ans[100] = "AB";
			int cost_ans = sumof_spec123(ans);
			char *res = NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;

			if (res == NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null");
			}
			testCommonRoute(res, ans, cost, cost_ans);

		};
		//Alphabatical cases -4

		TEST_METHOD(Real13_CommonRoute)
		{
			int cost = -1;
			char hacklist[100] = "ADBC";
			char codelist[100] = "BCAD";
			char ans[100] = "AD";
			int cost_ans = sumof_spec123(ans);
			char *res = NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;

			if (res == NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null");
			}
			testCommonRoute(res, ans, cost, cost_ans);

		};

		TEST_METHOD(Real20_CommonRoute)
		{
			int cost = -1;
			int len = 10000;
			char *hacklist = (char *)malloc(sizeof(char)*len);
			char *codelist = (char *)malloc(sizeof(char)*len);
			char *ans = (char *)malloc(sizeof(char)*len);;
			hacklist[0] = 'Z';
			codelist[0] = 'T';
			int k = 0;
			for (int i = 1; i < len - 1; i++){
					hacklist[i] = 'A';
					codelist[i] = 'A';
				ans[k] = 'A';
				k++;
			}
			hacklist[len - 1] = '\0';
			codelist[len - 1] = '\0';
			ans[k] = '\0';
			int cost_ans = sumof_spec123(ans);
			char *res = NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;

			if (res == NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null");
			}
			testCommonRoute(res, ans, cost, cost_ans);

		};
		TEST_METHOD(Real22_CommonRoute)
		{
			int cost = -1;
			int len = 2000;
			char *hacklist = (char *)malloc(sizeof(char)*len);
			char *codelist = (char *)malloc(sizeof(char)*len);
			char *ans = (char *)malloc(sizeof(char)*len);;
			hacklist[0] = 'Z';
			codelist[0] = 'T';
			int k = 0;
			for (int i = 1; i < len - 1; i++){
				hacklist[i] = 'A';
				codelist[i] = 'A';
				ans[k] = 'A';
				k++;
			}
			hacklist[len - 1] = '\0';
			codelist[len - 1] = '\0';
			ans[k] = '\0';
			int cost_ans = sumof_spec123(ans);
			char *res = NULL;
			res = find_common_route(hacklist, codelist, &cost);
			int check = 0;

			if (res == NULL){
				Assert::AreEqual(0, 1, L"Failed sample 2 for CommonRoute,Res is Null");
			}
			testCommonRoute(res, ans, cost, cost_ans);

		};



	};
}