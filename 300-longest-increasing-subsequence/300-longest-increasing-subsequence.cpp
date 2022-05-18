class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> seq;
        seq.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            
            if (num > seq[seq.size()-1]) {
                seq.push_back(num);
            } else {
                int j = search(seq, num);
                seq[j] = num;
            }
        }
        return seq.size();
    }
    
    int search(vector<int> seq, int val) {
        int left = 0, right = seq.size()-1;
        
        int ans = left;
        while (left <= right) {
            int mid = left +(right-left)/2;
            
            if (seq[mid] == val) return mid;
            
            if (seq[mid] > val) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return ans;
    }
};