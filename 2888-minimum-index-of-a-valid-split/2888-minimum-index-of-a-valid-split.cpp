class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // find dominant O(N)
        int n = nums.size();
        unordered_map<int, int> counter;
        int maxnumber = nums[0], maxnumbercount = 0;
        for (auto num: nums) {
            if (num == maxnumber) {
                maxnumbercount++;
            } else {
                maxnumbercount--;
            }
            if (maxnumbercount < 1) {
                maxnumbercount = 1;
                maxnumber = num;
            }
            counter[num]++;
        }
        // overall count and count at each index to find index.  O(N)
        maxnumbercount = 0;
        int overallCount = counter[maxnumber];

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == maxnumber) {
                maxnumbercount++;
            }

            bool leftSide = (maxnumbercount > ((i+1)/2));
            bool rightSide = ((overallCount - maxnumbercount) > ((nums.size() - (i+1))/2));
            if (leftSide && rightSide) return i;
        }
        return -1;
    }
};