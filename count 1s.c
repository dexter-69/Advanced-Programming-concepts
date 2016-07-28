#include<stdio.h>
long long int getcount(unsigned int n) {
	long long int county =0;
	for(int i=1; i<=n; i++) {
		unsigned int temp = i;
		while(temp) {
			temp&=(temp-1);
			++county;
		}
	}
	return county;
}
int main() {
	unsigned int n;
	scanf("%u",&n);
	long long int count= getcount(n);
	printf("%lld",count);
}
