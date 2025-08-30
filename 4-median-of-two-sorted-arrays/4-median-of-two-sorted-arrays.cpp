#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<int> median_idx;
        
        if (m+n & 1) {
            median_idx.push_back((m+n)/2);
        } else {
            median_idx.push_back((m+n)/2);
            median_idx.push_back((m+n)/2 -1);
        }
        
        double ans = 0;
        for (auto x : median_idx) {
          ans += findMedianSortedArrays(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, x);
        }
        
        return ans/median_idx.size();;
    }
    
    int findMedianSortedArrays(vector<int> &n1, int s1, int e1, vector<int> &n2, int s2, int e2, int median_idx) {
        // cout << s1 << " " << e1 << endl;
        // cout << s2 << " " << e2 << endl;
        if (s1 > e1) {
            return n2[median_idx - s1];
        }
        
        if(s2 > e2) {
            return n1[median_idx - s2];
        }
        int m1 = (s1 + e1)/2;
        int m2 = (s2 + e2)/2;
        int val1 = n1[m1];
        int val2 = n2[m2];
        
        if (m1 + m2 < median_idx) {
            if (val1 < val2) {
                return findMedianSortedArrays(n1, m1+1, e1, n2, s2, e2, median_idx);
            } else {
                return findMedianSortedArrays(n1, s1, e1, n2, m2+1, e2, median_idx);
            }
        // } else if (m1 + m2 + 1 > median_idx) {
        } else {
            if (val1  < val2) {
                return findMedianSortedArrays(n1, s1, e1, n2, s2, m2 - 1, median_idx);
            } else {
                return findMedianSortedArrays(n1, s1, m1 - 1, n2, s2, e2, median_idx);
            }
        }
        // } else {
        //     if (val1 < val2) {
        //         return findMedianSortedArrays(n1, s1, e1, n2, s2, m2, median_idx);
        //     } else {
        //         return findMedianSortedArrays(n1, s1, m1, n2, s2, e2, median_idx);
        //     }
        // }
    }
};
