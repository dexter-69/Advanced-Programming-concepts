#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) /* Function For Swapping */ {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
/*void insertion_sort( int *a, int n ) {
	for(int i = 0; i < n; i++) {
		int j = i;
		while( j > 0 && a[j-1] > a[j]) {
			swap(a[j-1], a[j]);
			--j;
		}
	}
}*/
/* A Slightly faster variant*/
void insertion_sort( int *a, int n ){
	for(int i = 0; i < n; i++) {
		int temp = a[i];
		int j = i - 1;
		while( j >= 0 && a[j] > temp) {
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = temp;
	}
}

int main() {
	int n;
	cout << "Enter Size of array\n";
	cin >> n;
	int a[n];
	cout << "Enter " << n << " Elements\n";
	for(int i = 0; i < n; i++)
	    cin >> a[i];
	insertion_sort(a, n);
	cout << "After Sorting\n";
	for(int i = 0; i < n; i++)
	    cout << a[i] << " ";
}	
