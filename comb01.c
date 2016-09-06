#include <stdio.h>
void fill0(int n);
void fill1(int n);


void fill0(int n)
{
    if(n==0)
    {
        return;
        printf("\n");
    }
    fill0(n-1);
    fill1(n-1);
    
    printf("0 ");
}

void fill1(int n)
{
    if(n==0)
    {
        return;
        printf("\n");
    }
    fill1(n-1);
    fill0(n-1);
    
    printf("1 ");
}

int main()
{
    int n;
    scanf("%d", &n);
    
    fill0(n);
}
