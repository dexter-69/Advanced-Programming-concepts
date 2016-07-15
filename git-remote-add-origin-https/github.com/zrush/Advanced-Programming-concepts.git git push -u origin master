#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	int zer_arr[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
		    cin >> zer_arr[i][j];
	}	
	
	int zer_rows = 0, zer_cols = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if( zer_arr[i][j] == 0 ) {
				zer_rows |= ( 1 << i );
				zer_cols |= ( 1 << i );
			}
		}
	}
	for(int i = 0; i < 32; i++) {
		if(( zer_rows & (1 << i)) != 0) {
			for(int j = 0; j < zer_cols; j++) {
				zer_arr[i][j] = 0;
			}
		}
	}	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
		    cout << zer_arr[i][j] << " ";
		    cout << endl;
	}	
	
	return 0;
}
