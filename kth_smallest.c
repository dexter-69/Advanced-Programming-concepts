#include <stdio.h>
#include <stdlib.h>

int quickSort(int *A, int Left, int Right);

int k;

int main()
{
    int elem, i, size;
    printf("\n\nEnter size of array: ");       
	scanf("%d", &size);
    int A[size];

    printf("\n\nEnter %d elements: \n", size);
	for(i = 0; i < size; i++) scanf("%d", &A[i]);

    printf("\n\nEnter k for kth smallest element: ");        
	scanf("%d", &k);

    printf("\n\nArray elements: ");             
	for(i = 0; i < size; i++) printf(" %d ", A[i]);
    printf("\n");

    elem = quickSort(A, 0, size-1);

    printf("\n\nQuick sorted till kth smaller is not found: ");               for(i = 0; i < size; i++) printf(" %d ", A[i]);
    printf("\n\n");

    printf("\n\n%dth smallest elem: %d", k, elem);
    printf("\n\n");

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x       = *y;
    *y       = temp;
}

int getRandomPivot(int L, int R)
{
    return (rand() % (R - L + 1)) + L;    // Return a random number in the range L to R.
}

int quickSort(int *A, int Left, int Right)
{
    int i, pos, pivot;
    if(Left < Right)
    {
        pivot = getRandomPivot(Left, Right);
        swap(&A[Left], &A[pivot]);        // Swap Left with the random pivot, then do Quick Sort where leftmost element acts as pivot.

        pos = Left;
        for(i = Left+1; i <= Right; i++)
            if(A[i] < A[Left])
                swap(&A[++pos], &A[i]);   // When order is mismatched, increment pos and swap A[pos] with A[i].

        swap(&A[Left], &A[pos]);          // By now, pos is at proper position for A[Left] (Left acts as pivot). Swap A[Left] with A[pos].

        if (pos == k-1)
            return A[pos];
        else if (pos > k-1)                     // If current pivot position pos is greater than k, recur for left subarray.
            return quickSort(A, Left, pos-1);
        else                                    // Else recur for right subarray.
            return quickSort(A, pos+1, Right);
    }

    return -1;
}
