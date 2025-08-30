#include <algorithm>
#include <vector>

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> lefttoright(n, -1);
        vector<int> righttoleft(n, -1);
        
        int maxleft = -1;
        int maxright = -1;
        for (int i = 0; i< n; ++i) {
            if (maxleft != -1 && height[i] > height[maxleft]) {
                lefttoright[i] = i;
                maxleft = i;
            }
            else if (maxleft == -1) {
                lefttoright[i] = i;
                maxleft = i;
            } else {
                lefttoright[i] = maxleft;
            }
            
            if (maxright != -1 && height[n-1-i] > height[maxright]) {
                righttoleft[n-1-i] = n-1-i;
                maxright = n-1-i;
            }
            else if (maxright == -1) {
                righttoleft[n-1-i] = n-1-i;
                maxright = n-1-i;
            } else {
                righttoleft[n-1-i] = maxright;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(height[lefttoright[i]],height[righttoleft[i]])-height[i];
        }
        
        return ans;
    }
};
