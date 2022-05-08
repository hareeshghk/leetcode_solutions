class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> maxtoleft(n), maxtoright(n);
        maxtoleft[0] = height[0];
        maxtoright[n-1] = height[n-1];
        for (int i = 1; i < n; ++i) {
            maxtoleft[i] = max(height[i], maxtoleft[i-1]);
            maxtoright[n-1-i] = max(height[n-1-i], maxtoright[n-i]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(maxtoleft[i], maxtoright[i])-height[i];
        }
        
        return ans;
    }
};