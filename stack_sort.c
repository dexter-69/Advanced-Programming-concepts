#include <stdio.h>
#define SIZE 100


void push(int *S, int top, int item)
{
    if(top == SIZE-1)
    {
        printf("\nStack overflow.");
        return;
    }
    
    S[++top] = item;
}

void pop(int *S, int top)
{
    if(top == 0)
    {
        printf("\nStack underflow.");
        return;
    }
    
    --top;
}

int peek(int *S, int top)
{
    if(top == 0)
    {
        printf("\nStack underflow.");
        return -1;
    }
    
    return S[top];
}

void show(int *S, int top)
{
    int i;
    printf("\n");
    for(i=0; i<=top; i++)
        printf("%d ", S[i]);
    printf("\n");
}

        void compare(int *, int );
        void sort(int *, int , int);

void sort(int *S, int cur, int TOP)
{
    if(cur == 0)
        return;
    else
    {
        compare(S, TOP);
        return sort(S, cur-1, TOP);
    }
}


void compare(int *S, int top)
{
    if(top == 0)
        return;
    else
    {
        if(S[top] < S[top-1])
        {
            int temp = S[top];
            S[top] = S[top-1];
            S[top-1] = temp;
        }
        
        return compare(S, top-1);
    }
}

int main()
{
    int top = -1;
    int S[SIZE];
    int i;
    for(i= 8; i>=1; i--)
    {
        S[++top] = i;
    }
    
    
    show(S, top);
    
   sort(S, top, top);
   show(S, top);
 }
