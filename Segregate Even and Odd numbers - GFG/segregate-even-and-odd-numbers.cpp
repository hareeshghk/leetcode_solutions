// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void segregateEvenOdd(int arr[], int n) {
	    sort(arr, arr+n, [](int a, int b){
	        if ((a%2 == 0) && (b%2 != 0)) {
	            return true;
	        } else if (a%2 != 0 && b%2 == 0) {
	            return false;
	        } else {
	            return a < b;
	        }
	    });
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends