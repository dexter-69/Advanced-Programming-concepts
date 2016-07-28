#include<stdio.h>
unsigned int swapNibbles(unsigned int x) {
	return ((x&0x0F)<<4|(x&0xF0)>>4);
}
int main() {
	unsigned int x;
	scanf("%u",&x);
	printf("%u",swapNibbles(x));
}
