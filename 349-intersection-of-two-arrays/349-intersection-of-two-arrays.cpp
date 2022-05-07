class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1, n2;
        vector<int> result;
        
        for (auto num : nums1) {
            n1.insert(num);
        }
        
        for (auto num : nums2) {
           if (n1.count(num) != 0) {
               n2.insert(num);
           }
        }
        
        for (auto v : n2) {
            result.push_back(v);
        }
        return result;
    }
};