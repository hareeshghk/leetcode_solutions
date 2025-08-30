#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the index where increasing order from back breaks
        int idx = -1, n = nums.size();
        for (int i = n-1; i >0; --i) {
            if (nums[i] > nums[i-1]) {
                idx = i-1;
                break;
            }
        }
        
        // given order is in decreasing order so next permutation is sorted order of all.
        if (idx == -1) {
            rearrangeNums(nums, 0, n-1);
            return;
        }

        // swap the broke point with next greater element on right using binary search
        int left = idx+1, right = n-1;
        int nextGreaterIdx = findnextgreater(nums, left, right, idx);
        swap(nums[idx], nums[nextGreaterIdx]);
        // sort the right values, since they are in decresing order just swp and forst and last.
        rearrangeNums(nums, left, right);
    }
    
    void rearrangeNums(vector<int> &nums, int left, int right) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
    
    int findnextgreater(vector<int> &nums, int left, int right, int idx) {
        int mid;
        int ans=left;
        while (left <= right) {
            mid = left + (right-left)/2;
            if (nums[mid] <= nums[idx]) {
                right = mid-1;
            } else {
                ans = mid;
                left = mid+1;
            }
        }
        return ans;
    }
};
