/******************************************************************************
http://practice.geeksforgeeks.org/problems/champagne-overflow/0
There is a stack of water glasses in a form of pascal triangle and a person wants to pour the water at the topmost glass, but the capacity of each glass is 1 unit.
Overflow takes place in such a way that after 1 unit, 1 / 2 of remaining unit gets into bottom left glass and other half in bottom right glass.
Now we want to pour K units of water in the topmost glass and wants to know how much water is there in the jth glass of the ith row.
*******************************************************************************/
/******************************************************************************
Input:
First line of the input contains an integer T denoting the number of test cases and each test case consists of three lines.
First line contain an integer K, second line contains an integer i and third line contains an integer j.
Output: Corresponding to each test case output the remaining amount of water in jth cup of the ith row correct to 6 decimal places.
Constraints:
T <= 20
K <= 1000
i <= K
j <= K
*******************************************************************************/
/******************************************************************************
Example :
Input:
1 //No. Of Test cases
3 // K liter Water
2 // ith Row
1 //jth cup
Output :
1
*******************************************************************************/

#include <iostream>
#include <cstring>
#include <iomanip> 
using namespace std;

void ErrorLog()
{
	cout << fixed << setprecision(6);
	cout << 0 << endl;
}

void PascalWater(int nRow, int nCol, int nTotalWater)
{
	int nTotalGlasses = ((nRow * (nRow + 1))) / 2;
	double* dGlassWater = new double[nTotalGlasses];
	double dTotalWater = static_cast <double> (nTotalWater);

	memset(dGlassWater, 0, (nTotalGlasses * sizeof(double))); //Set all to 0.0

	int index = 0;
	dGlassWater[index] = dTotalWater;

	for (int row = 1; (row <= nRow) && (dTotalWater >= 0.0); row++)
	{
		for (int col = 1; col <= row; ++col, ++index)
		{
			dTotalWater = dGlassWater[index];

			if (dTotalWater > 1.0)
			{
				dGlassWater[index] = 1.0;
				dTotalWater -= 1.0;
			}
			else
			{
				dGlassWater[index] = dTotalWater;
				dTotalWater = 0.0;
			}

			if (index + row < nTotalGlasses)
			{
				dGlassWater[index + row] += dTotalWater / 2.0;
			}
			if (index + row + 1 < nTotalGlasses)
			{
				dGlassWater[index + row + 1] += dTotalWater / 2.0;
			}
		}
	}

	cout << fixed << setprecision(6);
	cout << dGlassWater[nTotalGlasses - nRow + nCol - 1] << endl;

	delete[] dGlassWater;
}

int PascalTriangleWater()
{
	int nNoTestCases = 0;
	cin >> nNoTestCases;

	if ((nNoTestCases < 1) || (nNoTestCases > 21))
		return -1;

	for (int nCurTest = 0; nCurTest < nNoTestCases; nCurTest++)
	{
		/**********************************************************************
		* Input Read and Validation
		**********************************************************************/
		int nTotalWater = 0;
		cin >> nTotalWater;

		if ((nTotalWater < 0) || (nTotalWater > 1001))
		{
			ErrorLog(); continue;
		}

		int nRow = 0;
		cin >> nRow;

		if ((nRow < 1) || (nRow > (nTotalWater + 1)))
		{
			ErrorLog(); continue;
		}

		int nCol = 0;
		cin >> nCol;

		if ((nCol < 1) || (nCol > (nTotalWater + 1)) || (nCol > nRow)) // Column No. can't be greater than Row No.
		{
			ErrorLog(); continue;
		}

		// Base Results
		if (0 == nTotalWater)
		{
			ErrorLog(); continue;
		}

		PascalWater(nRow, nCol, nTotalWater);
	}

	return 0;
}