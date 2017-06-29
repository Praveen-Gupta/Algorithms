/******************************************************************************
MergeSort(arr[], l, r)
If r > l
1. Find the middle point to divide the array into two halves :
middle m = (l + r) / 2
2. Call mergeSort for first half :
Call mergeSort(arr, l, m)
3. Call mergeSort for second half :
Call mergeSort(arr, m + 1, r)
4. Merge the two halves sorted in step 2 and 3 :
	Call merge(arr, l, m, r)
******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <memory>

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void merge(int pArr[], int nStart, int nMid, int nEnd)
{
	for (int i = nStart; i < nEnd; i++)
	{
		std::cout << "Before Merge: ";
		std::cout << pArr[i] << " , ";
	}
	std::cout << std::endl;

	int nLeft = nMid - nStart + 1;
	int nRight = nEnd - nMid;

	int *pRight = new int[nRight];
	int *pLeft = new int[nLeft];

	for (int i = 0; i < nLeft; i++)
	{
		pLeft[i] = pArr[i + nStart];
	}

	for (int i = 0; i < nRight; i++)
	{
		pRight[i] = pArr[i + nMid +1];
	}

	int i = 0, j = 0, k = nStart;

	while ((i < nLeft) && (j < nRight))
	{
		if (pLeft[i] <= pRight[j])
		{
			pArr[k] = pLeft[i];
			i++;
		}
		else
		{
			pArr[k] = pRight[j];
			j++;
		}
		k++;
	}

	while (i < nLeft)
	{
		pArr[k] = pLeft[i];
		i++;
		k++;
	}

	while (j < nRight)
	{
		pArr[k] = pRight[j];
		j++;
		k++;
	}

	for (int i = nStart; i < nEnd; i++)
	{
		std::cout << "After Merge: ";
		std::cout << pArr[i] << " , "; 
	}

	std::cout << std::endl;

	delete pRight;
	delete pLeft;
}

void mergeSort(int pArr[], int nStart, int nEnd)
{
	if (nStart < nEnd)
	{
		int nMid = (nStart + nEnd) / 2;

		mergeSort(pArr, nStart, nMid);
		mergeSort(pArr, nMid + 1, nEnd);

		merge(pArr, nStart, nMid, nEnd);
	}
}

int main2()
{
	int arr[] = { 12, 11, 13, 5, 6, 7,-1,4,7,8,9,0,-1,0,12,12};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}