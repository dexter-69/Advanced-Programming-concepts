// Array is shifted by some unknown posiions. 5 7 9 13 18  ->  13 18 5 7 9.
// Now do binary search. Algorithms should be O(logN) only.


#include <stdio.h>
#include <stdlib.h>

int binary_search(int *, int, int, int);

int find_offset(int *A, int start, int end)
{
    int mid;

    if(start <= end)
    {
      mid = (start + end) / 2;

      if(A[mid] > A[mid+1])
        return mid;
      else if(A[mid] > A[end])
        find_offset(A, mid, end);
      else
    	find_offset(A, start, mid);
    }
    else
        return -1;
}




int main()
{
    int i, N, offset, num, res;

    printf("\nEnter size: ");
    scanf("%d", &N);
    int A[N];

    printf("\nEnter elements: ");
    for(i = 0; i < N; i++)
    {
      scanf("%d", &A[i]);
    }

    for(i = 0; i < N; i++)
    {
      printf("%d ", A[i]);
    }

    printf("\nEnter number to search: ");
    scanf("%d", &num);

    offset = find_offset(A, 0, N-1);
    
    printf("\n\nOffset at: %d\n", offset);

    if(offset == -1)
    {
        res = binary_search(A, 0, N-1, num);
        if(res==-1) printf("\n\nNOT FOUND!\n\n");
        else printf("Found at index  %d\n\n", res);
    }
    else
    {
        res = binary_search(A, 0, offset, num);        
        if(res == -1)
        {
            res = binary_search(A, offset+1, N-1, num);
            if(res==-1) printf("\n\nNOT FOUND!\n\n");
            else printf("Found at index  %d\n\n", res);
        }
        else
        {
            printf("Found at index  %d\n\n", res);
        }   
    }
    
    return 0;
}


int binary_search(int *A, int start, int end, int num)
{
    int mid;

    if(start<=end)
    {
      mid = (start + end) / 2;
      
      if(A[mid] == num)
	  return mid;
      else if(A[mid] > num)
	  binary_search(A, start, mid-1, num);
      else
	  binary_search(A, mid+1, end, num);
    }

    else return -1;
}

