#include <iostream>
#include <array>
#include <algorithm>
#include<vector>
#include<list>
#include <cmath>
#include <cstring>
using namespace std;

/******************************************************************************
http://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers/0
Find all four sum numbers
Given an array A of size N, find all combination of four elements in the array
whose sum is equal to a given value K.
For example, if the given array is{ 10, 2, 3, 4, 5, 9, 7, 8 } and K = 23,
one of the quadruple is “3 5 7 8”(3 + 5 + 7 + 8 = 23).
******************************************************************************/
/******************************************************************************
Input:
The first line of input contains an integer T denoting the no of test cases.
Then T test cases follow.Each test case contains two lines.
The first line of input contains two integers N and K.
Then in the next line are N space separated values of the array.
******************************************************************************/
/******************************************************************************
Output:
For each test case in a new line print all the quadruples present in the array separated by space
which sums up to value of K.Each quadruple is unique which are separated by a delimeter "$"
and are in increasing order.
Example :
Input :
2
5 3
0 0 2 1 1
7 23
10 2 3 4 5 7 8
Output :
0 0 1 2 $
2 3 8 10 $2 4 7 10 $3 5 7 8 $
******************************************************************************/
/******************************************************************************
Constraints:
1 <= T <= 100
1 <= N <= 100
- 1000 <= K <= 1000
- 100 <= A[] <= 100
******************************************************************************/
class Node
{
public:
	int nFirst;
	int nSecond;
};

//Expects Sorted Array
void FindSumOfFour(int pArr[], int nArraySize, int nDesiredSumOfFour)
{
	vector <vector<int>> vPrintVect;
	int nSumFirstTwo = pArr[0] + pArr[1];
	int nSumLastTwo = pArr[nArraySize - 2] + pArr[nArraySize - 1];

	nDesiredSumOfFour -= (2 * nSumFirstTwo);

	int nVectorSize = nDesiredSumOfFour + 1;
	std::vector <std::list <Node>> vTwoSum(nVectorSize);
	vTwoSum.reserve(nVectorSize);

	for (int i = 0; i < nArraySize; i++)
	{
		for (int j = i + 1; j < nArraySize; j++)
		{

			int nVal = pArr[i] + pArr[j] - nSumFirstTwo;
			if (nVal <= nDesiredSumOfFour)
			{
				Node cCurrNode;
				cCurrNode.nFirst = i;
				cCurrNode.nSecond = j;
				vTwoSum[nVal].push_back(cCurrNode);
			}
		}
	}

	for (int i = 0; i < ceil(nDesiredSumOfFour / 2); i++)
	{
		if (!(vTwoSum[i].empty()))
		{

			std::list <Node> myList;
			if (!(vTwoSum[nDesiredSumOfFour - i].empty()))
			{
				for (auto First : vTwoSum[i])
				{
					for (auto Second : vTwoSum[nDesiredSumOfFour - i])
					{
						if ((First.nFirst == Second.nFirst) ||
							(First.nFirst == Second.nSecond) ||
							(First.nSecond == Second.nFirst) ||
							(First.nSecond == Second.nSecond) ||
							(First.nSecond > Second.nFirst))
						{
							continue;
						}


						vector<int> CurrArr = { pArr[First.nFirst] ,pArr[First.nSecond] ,pArr[Second.nFirst], pArr[Second.nSecond] };

						sort(CurrArr.begin(), CurrArr.end());

						vPrintVect.push_back(CurrArr);
					}
				}
			}
		}
	}

	sort(vPrintVect.begin(), vPrintVect.end());

	if (vPrintVect.empty())
	{
		cout << -1 << endl;
		return;
	}

	vector<int> vLast{ -1, -1, -1, -1 };

	for (auto it : vPrintVect)
	{
		bool bSame = true;

		for (int i = 0; i < 4; i++)
		{
			if (vLast[i] != it[i])
			{
				bSame = false;
				break;
			}
		}

		if (!bSame)
		{
			for (int i = 0; i < 4; i++)
			{
				vLast[i] = it[i];
				cout << it[i] << " ";
			}
			cout << "$";
		}
	}

	cout << endl;
}

int SumOf4Element()
{
	int nNoTestCases = 0;
	cin >> nNoTestCases;

	if ((nNoTestCases < 1) || (nNoTestCases > 101))
		return -1;

	for (int nCurTest = 0; nCurTest < nNoTestCases; nCurTest++)
	{
		/**********************************************************************
		* Input Read and Validation
		**********************************************************************/
		int nArraySize = 0;
		cin >> nArraySize;

		if ((nArraySize < 4) || (nArraySize > 100))
		{
			cout << -1 << endl; continue;
		}

		int nDesiredSumOfFour = 0;
		cin >> nDesiredSumOfFour;

		if ((nDesiredSumOfFour < -1000) || (nDesiredSumOfFour > 1000))
		{
			cout << -1 << endl; continue;
		}

		int* pArr = new int[nArraySize];
		memset(pArr, 0, nArraySize * sizeof(int));

		int err = 0;
		for (int i = 0; i < nArraySize && err != -1; i++)
		{
			int nVal = 0;
			cin >> nVal;

			if ((nVal < -101) || (nVal > 100))
			{
				err = -1;
				cout << -1 << endl;
				delete[] pArr;
				continue;
			}
			else
			{
				pArr[i] = nVal;
			}
		}

		if (0 == err)
		{
			sort(pArr, pArr + nArraySize);

			int nSumFirstFour = pArr[0] + pArr[1] + pArr[2] + pArr[3];
			int nSumLastFour = pArr[nArraySize - 4] + pArr[nArraySize - 3] + pArr[nArraySize - 2] + pArr[nArraySize - 1];

			//Base Tests
			if (4 == nArraySize)
			{
				if (nDesiredSumOfFour == nSumFirstFour)
				{
					for (int i = 0; i < nArraySize; i++)
					{
						cout << pArr[i] << " ";
					}
					cout << "$" << endl;
					delete[] pArr;
					continue;
				}
			}
			else if (nSumFirstFour > nDesiredSumOfFour)
			{
				cout << "-1" << endl;
				delete[] pArr;
				continue;
			}
			else if (nSumLastFour < nDesiredSumOfFour)
			{
				cout << "-1" << endl;
				delete[] pArr;
				continue;
			}
			else
			{
				FindSumOfFour(pArr, nArraySize, nDesiredSumOfFour);
				delete[] pArr;
			}
		}
	}

	return 0;
}