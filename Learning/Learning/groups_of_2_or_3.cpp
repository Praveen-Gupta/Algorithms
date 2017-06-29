/******************************************************************************
You are given N distinct numbers. You are tasked with finding the number of groups
of 2 or 3 that can be formed whose sum is divisible by three.

Example:
Input  : 1 5 7 2 9 14
Output : 13
The groups of two that can be
formed are:
(1, 5)
(5, 7)
(1, 2)
(2, 7)
(1, 14)
(7, 14)
The groups of three are:
(1, 5, 9)
(5, 7, 9)
(1, 2, 9)
(2, 7, 9)
(2, 5, 14)
(1, 9, 14)
(7, 9, 14)
******************************************************************************/

#include <iostream>
using namespace std;

int numOfCombinations(int arr[], int N)
{
	// Initialize groups to 0
	int C[3] = { 0, 0, 0 };

	// Increment group with specified remainder
	for (int i = 0; i < N; ++i)
	{
		++C[arr[i] % 3];
	}

	// Return groups using the formula

	return C[1] * C[2] + C[0] * (C[0] - 1) / 2 +
		C[0] * (C[0] - 1) * (C[0] - 2) / 6 +
		C[1] * (C[1] - 1) * (C[1] - 2) / 6 +
		C[2] * (C[2] - 1) * (C[2] - 2) / 6 +
		C[0] * C[1] * C[2];

}

// Driver Function
int GroupOf2Or3()
{
	//Test Cases
	int arr1[7] = { 1, 5, 7, 2, 9, 14, 17 };
	cout << numOfCombinations(arr1, 7) << "\n";

	int arr2[4] = { 3, 6, 9, 12 };
	cout << numOfCombinations(arr2, 4) << "\n";

	return 0;
}