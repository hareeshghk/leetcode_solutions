class SparseVector {
public:
    vector<pair<int,int>> pos;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) pos.push_back(pair<int,int>(i, nums[i]));
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        
        int m = pos.size(), n = vec.pos.size();
        
        int i = 0, j = 0;
        
        while (i < m &&j < n) {
            if (pos[i].first == vec.pos[j].first) {
                result += pos[i].second * vec.pos[j].second;
                ++i;
                ++j;
            } else if (pos[i].first < vec.pos[j].first) {
                ++i;
            } else {
                ++j;
            }
        }
        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);