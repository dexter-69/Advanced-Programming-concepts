#include<bits/stdc++.h>
using namespace std;
void getByte(unsigned int n, int ex) {
	unsigned res = (n >> 8 *(ex))&0xFF;
	printf("%x",res);
}
int main() {
   unsigned	int n,ex;
   scanf("%x%u",&n,&ex);
   getByte(n,ex);	
}
