#include <stdio.h>
#include <stdlib.h>

int MinimumDifference(int n, int* pOilmines, int nNoOfMines)
{
	if (nNoOfMines < n)
	{
		return -1;
	}
	if (pOilmines != nullptr && nNoOfMines > 0 && n > 0)
	{
		double nMeanVal = 0.0;

		for (int i = 0; i < nNoOfMines; i++)
		{
			nMeanVal += pOilmines[i];
		}

		nMeanVal /= n;

		int *pCurrentAllocation = (int*)malloc(n * sizeof(int));
		int j = 0;
		int nMaxAllocation = 0, nMinAllocation = 0;

		for (int i = 0; i < n; i++)
		{
			pCurrentAllocation[i] = 0;

			if (n == nNoOfMines)
			{
				pCurrentAllocation[i] = pOilmines[i];
			}
			else
			{
				while (j < nNoOfMines && pCurrentAllocation[i] < nMeanVal)
				{
					pCurrentAllocation[i] += pOilmines[j];
					j++;
				}

				if (j < nNoOfMines)
				{
					if ((pCurrentAllocation[i] - nMeanVal) > (nMeanVal - (pCurrentAllocation[i] - pOilmines[j - 1])))
					{
						pCurrentAllocation[i] = pCurrentAllocation[i] - pOilmines[j - 1];
						j--;
					}
				}
			}
			if (pCurrentAllocation[i] > nMaxAllocation)
			{
				nMaxAllocation = pCurrentAllocation[i];
			}
			if (0 == i)
			{
				nMinAllocation = pCurrentAllocation[i];
			}
			if (pCurrentAllocation[i] < nMinAllocation)
			{
				nMinAllocation = pCurrentAllocation[i];
			}
		}

		free(pCurrentAllocation);

		return nMaxAllocation - nMinAllocation;
	}

	return -1;
}

int main3()
{
	int nNoOfCompanies = -1;
	int nNoOfMines = -1;

	printf("\n No. Of companies : ");
	scanf("%d", &nNoOfCompanies);

	if (nNoOfCompanies < 1)
	{
		printf("-1"); // Error
		return -1;
	}

	printf("\n No. Of oil mines : ");
	scanf("%d", &nNoOfMines);

	if (nNoOfMines < nNoOfCompanies)
	{
		printf("-1"); // Error
		return -1;
	}

	int *pArr = (int*)malloc(nNoOfMines * sizeof(int));
	if (!pArr)
	{
		printf("Failed to allocate memory");
		return -1;
	}

	for (int i = 0; i < nNoOfMines; i++)
	{
		scanf("%d", &pArr[i]);
		if (pArr[i] < 1)
		{
			printf("-1"); // Error
			return -1;
		}
	}

	/**************************************************************************
	Run MinimumDifference Algo
	**************************************************************************/
	printf("\n Min Diff = %d\n", MinimumDifference(nNoOfCompanies, pArr, nNoOfMines));

	free(pArr);

	return 0;
}