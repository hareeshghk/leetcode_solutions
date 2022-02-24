class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counter;
        
        for (auto num:nums) {
            counter[num]++;
            if(counter[num] > (n/2)) return num;
        }
        return 0;
    }
};