#include <stdio.h>
#include <stdlib.h>

void LargestSum(int *pArr, int nLen, int k)
{
	long long nMaxSofar = INT_MIN;
	long long nMaxEndingHere = 0;

	for (int i = 0; i < k; i++)
	{
		nMaxEndingHere += pArr[i];
	}

	for (int i = k; i < nLen; i++)
	{
		nMaxEndingHere += pArr[i];
		if (nMaxSofar < nMaxEndingHere)
		{
			nMaxSofar = nMaxEndingHere;
		}
	}

	printf("%lld\n", nMaxSofar);

}
int main1()
{
	unsigned int nTestCases = 0;
	scanf("%d", &nTestCases);
	printf("\n%d\n", nTestCases);

	/**************************************************************************
	Read Input for Each Test case
	**************************************************************************/
	for (unsigned int i = 0; i < nTestCases; i++)
	{
		unsigned int nArrSize = 0;
		int k = 0;
		scanf("%d", &nArrSize);
		printf("\n%d\n", nArrSize);

		int *pArr = (int*)malloc(nArrSize * sizeof(int));

		for (unsigned int j = 0; j < nArrSize; j++)
		{
			scanf("%d", &pArr[j]);
		}

		scanf("%d", &k);

		/**************************************************************************
		Run Largest Sum  Algo for Current array
		**************************************************************************/
		LargestSum(pArr, nArrSize,k);
	}
	return 0;
}