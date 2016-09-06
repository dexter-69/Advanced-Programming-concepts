/*  Given a nearly sorted array with only the last element incorrectly placed, insert it at correct position in the array. Show array at each step.

    Ip. 5
        1 2 4 5 3

    Op. 1 2 4 5 5
        1 2 4 4 5
        1 2 3 4 5
*/

#include <stdio.h>
void InsertionSortWithSteps(int N, int *A);
void print_arr(int N, int *A);

int main()
{
    int N, i;
    scanf("%d", &N);
    int A[N];
    for(i=0; i<N; i++)
        scanf("%d", &A[i]);
        
    InsertionSortWithSteps(N, A);
}

void InsertionSortWithSteps(int N, int *A)
{
    int j, pivot = A[N-1];
    for(j = N-2; j >= 0; j--)
        if(A[j] > pivot && (A[j+1] = A[j]))     //Same as if(A[j] > pivot){ A[j+1] = A[j]; print_arr(N, A); } else ..
            print_arr(N, A);
        else
            break;
            
    A[j+1] = pivot;
    print_arr(N, A);    
}

void print_arr(int N, int *A)
{
    int i = 0;
    while(i < N)
        printf("%d ", A[i++]);
    printf("\n");
}
