#include <iostream>
using namespace std;
int ind;
int find_where_shifted(int *arr, int l, int r) {
    while(l <= r) {
    	int m = (l+r)/2;
    	if(arr[m] < arr[m-1]) 
    	    return m;
        if(arr[m] > arr[m-1] && arr[m] < arr[m+1]) 
            r = m-1;
        else l = m+1; 
    }
    return -1;
}
bool bin_search(int *arr,int l ,int r,int x) {
    while (l <= r)
  {
    int m = l + (r-l)/2;
 
    // Check if x is present at mid
    if (arr[m] == x) 
        return true;  
 
    // If x greater, ignore left half  
    if (arr[m] < x) 
        l = m + 1; 
 
    // If x is smaller, ignore right half 
    else
         r = m - 1; 
  }
 
  // if we reach here, then element was not present
  return false; 
}
int main() {
	// your code goes here
	int n;
	cin >> n;
	int *a= new int [n];
	for(int i = 0; i < n; i++) 
        cin >> a[i];
        int ele;
        cout << "Enter Element to search\n";
        cin >> ele;
        int res;
	res = find_where_shifted(a, 0, n);
	if(bin_search(a,res,n-1,ele))
            cout << "Element found ";
        else cout << "Not Found";
	return 0;
}
