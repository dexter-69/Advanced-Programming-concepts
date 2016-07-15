#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) /* Function For Swapping */ {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
void insertion_sort( int *a, int n ) /* Insertion Sort Begins Here */ {
	for(int i = 0; i < n; i++) {
		int j = i;
		while( j > 0 && a[j-1] > a[j]) {
			swap(a[j-1], a[j]);
			--j;
		}
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
