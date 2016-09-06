#include <stdio.h>

long long countSetBits(int N) {
    int i, a;
    long long count = 0;
    for(i = 1; i <= N; i++) {
        a = i;
        while(a) {
            if(a & 1)
                count++;
            a >>= 1;
        }
    }
    
    return count;
}

int main()
{
    int N;
    long long count;

    while(1) {
        printf("\n\n\tEnter N to count set bits in all numbers from 1 to N: ");
        scanf("%d", &N);
        count = countSetBits(N);
        printf("\n\tSet bits in nos from 1 to %d = %lld \n", N, count);
    }
    
    return 0;
}
