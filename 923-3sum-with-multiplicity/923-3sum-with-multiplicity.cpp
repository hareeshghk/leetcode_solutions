class Solution {
public:
    const int mod = 1000000007;
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, int> prev_sums;
        prev_sums[arr[0]+arr[1]] = 1;
        int n = arr.size();
        int result = 0, cursum;
        for (int i = 2; i < n; i++) {
            cursum = target-arr[i];
            if (prev_sums.find(cursum) != prev_sums.end()) {
                result = (result + prev_sums[cursum])%mod;
            }
            
            for (int j = i-1; j>=0;j--) {
                prev_sums[arr[i]+arr[j]]++;
            }
        }
        return result;
    }
};