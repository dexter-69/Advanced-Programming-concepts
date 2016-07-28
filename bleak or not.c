#include<stdio.h>
int get_total_ones(unsigned int x) {
	int count = 0;
	while(x) {
		x&=(x-1);
		++count;
	}
	return count;
}
bool check_bleak(unsigned int n) {
	int get_count = get_total_ones(n);
	for(int i = 1; i <= get_count; i++) {
		if(get_total_ones(n-i)==i)
		    return 0;
	}
	return 1;
}
int main() {
	unsigned int n;
	scanf("%u",&n);
	bool check = check_bleak(n);
	if(check)
	    printf("Number is bleak");
	else printf("Number is not bleak");
	return 0;.
	    
}
