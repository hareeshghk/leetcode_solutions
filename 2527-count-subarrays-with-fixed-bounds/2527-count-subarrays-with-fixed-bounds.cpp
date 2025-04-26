class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        // use monotnic stack to finf nearest big on the left and right also nearest smallest on left and right
        // O(N) for both
        stack<int> stSmall;
        stack<int> stLarge;

        vector<int> nearestSmallToLeft = vector<int>(n, -1);
        vector<int> nearestSmallToRight = vector<int>(n, n);
        vector<int> nearestBigToLeft = vector<int>(n, -1);
        vector<int> nearestBigToRight = vector<int>(n, n);


        for (int i = 0; i < n; ++i) {
            while (!stSmall.empty() && nums[stSmall.top()] >= nums[i]) {
                stSmall.pop();
            }

            if (!stSmall.empty()) {
                nearestSmallToLeft[i] = stSmall.top();
            }
            stSmall.push(i);

            while (!stLarge.empty() && nums[stLarge.top()] <= nums[i]) {
                stLarge.pop();
            }

            if (!stLarge.empty()) {
                nearestBigToLeft[i] = stLarge.top();
            }
            stLarge.push(i);
        }

        stSmall = stack<int>();
        stLarge = stack<int>();
        for (int i = n-1; i >= 0; --i) {
            while (!stSmall.empty() && nums[stSmall.top()] >= nums[i]) {
                stSmall.pop();
            }

            if (!stSmall.empty()) {
                nearestSmallToRight[i] = stSmall.top();
            }
            stSmall.push(i);

            while (!stLarge.empty() && nums[stLarge.top()] <= nums[i]) {
                stLarge.pop();
            }

            if (!stLarge.empty()) {
                nearestBigToRight[i] = stLarge.top();
            }
            stLarge.push(i);
        }

        vector<int> minkRange = vector<int>{-1, -1, -1};
        vector<int> maxkRange = vector<int>{-1, -1, -1};
        long long answer = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == minK) {
                if (i >= minkRange[0] && i <= minkRange[1]) {
                    minkRange[2] = i;
                } else {
                    minkRange[0] = nearestSmallToLeft[i] + 1;
                    minkRange[1] = nearestSmallToRight[i] - 1;
                    minkRange[2] = i;
                }
            }

            if (nums[i] == maxK) {
                if (i >= maxkRange[0] && i <= maxkRange[1]) {
                    maxkRange[2] = i;
                } else {
                    maxkRange[0] = nearestBigToLeft[i] + 1;
                    maxkRange[1] = nearestBigToRight[i] - 1;
                    maxkRange[2] = i;
                }
            }

            // with i as last element how many subarrays possible.
            int fixedLeft = min(minkRange[2], maxkRange[2]);
            int maxRight = min(minkRange[1], maxkRange[1]);
            int commonLeft = max(minkRange[0], maxkRange[0]);

            if (i > maxRight) continue;

            answer = answer + max(0, fixedLeft-commonLeft+1);
        }
        return answer;
    }
};