#include <iostream>
#include <algorithm>
using namespace std;

int TrapWater(int Arr[], int nLen)
{
	if (nLen < 3)
		return 0;	// Return in In-Valid cases

	int* TrapWater = new int[nLen];
	memset(TrapWater, 0, nLen * sizeof(int));

	int nCurrMax = 0;
	int nTotalSum = 0;

	for (int i = 1; i < nLen; i++)
	{
		TrapWater[i] = std::max(nCurrMax, Arr[i - 1]);
		nCurrMax = TrapWater[i];
	}

	TrapWater[nLen - 1] = TrapWater[0] = nCurrMax =  0;

	for (int i = (nLen - 1); i > 0; i--)
	{
		int RightMax = std::max(nCurrMax, Arr[i + 1]);
		nCurrMax = RightMax;
		TrapWater[i] = std::min(TrapWater[i], RightMax);
	}

	for (int i = 1; i < nLen - 1; i++)
	{
		int nCurrDiff = (TrapWater[i] - Arr[i]);
		if (nCurrDiff > 0)
		{
			nTotalSum += nCurrDiff;
		}
	}

	delete[] TrapWater;
	return nTotalSum;
}

int TrapWaterTest()
{
	 //Test Case - 1 - Returns 27
	{
		int Arr[10] = { 4,0,0,6,0,0,5,0,7,7 };
		int nLen = sizeof(Arr) / sizeof(Arr[0]);
		cout << TrapWater(Arr, nLen) << endl;
	}

	// Test Case - 2 - Return 15
	{
		int Arr[7] = { 4,0,7,0, 6,0, 5 };
		int nLen = sizeof(Arr) / sizeof(Arr[0]);
		cout << TrapWater(Arr, nLen) << endl;
	}

	// Test Case - 3 - Return 4
	{
		int Arr[4] = { 4,0,6};
		int nLen = sizeof(Arr) / sizeof(Arr[0]);
		cout << TrapWater(Arr, nLen) << endl;
	}

	return 0;

}