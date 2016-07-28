#include<stdio.h>
bool divi_by_8(unsigned int n) {
	return ((n >> 3)<<3) == n;
}
int main() {
    unsigned int n;
    scanf("%u",&n);
    if(divi_by_8(n))
        printf("Divisible by 8");
    else printf("Not divisible by 8");
	return 0;    
}
