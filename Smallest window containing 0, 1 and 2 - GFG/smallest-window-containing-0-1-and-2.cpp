// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        unordered_map<char, int> counter;
        int s_len = S.length();
        int windowStart = 0;
        int small_sub_len = INT_MAX;
        for (int windowEnd = 0; windowEnd < s_len; ++windowEnd) {
            counter[S[windowEnd]] = windowEnd;
            if (counter.size() == 3) {
                while (windowEnd >= windowStart) {
                    if (counter[S[windowStart]] != windowStart) windowStart++;
                    else break;
                }
                small_sub_len = min(small_sub_len, windowEnd-windowStart+1);
            }
        }
        return small_sub_len == INT_MAX?-1:small_sub_len;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends