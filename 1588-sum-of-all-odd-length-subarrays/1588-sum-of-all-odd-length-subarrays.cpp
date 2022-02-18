class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        
        int max_odd = (n&1)?n:n-1;
        
        int ans = 0;
        for (int i = 0 ; i < n; ++i) {
            for (int j = 1; j <= max_odd; j+=2) {
                // cout << min(j, min(i+1, n-i)) << " ";
                ans += arr[i]*(min(j, i+1) - max(0, i+j-n));
            }
            // cout << endl;
        }
        return ans;
    }
};