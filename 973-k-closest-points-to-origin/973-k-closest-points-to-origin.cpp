class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        int left = 0, right = n-1, wallidx = n;
        
        while (left <= right) {
            wallidx = partition(points, left, right);
            
            if (wallidx+1 <= k) {
                left = wallidx+1;
            } else {
                right = wallidx-1;
            }
            
            // for (int i = 0; i < n; ++i) {
            //     cout << points[i][0] << " " << points[i][1] << " ";
            // }
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(points[i]);
        }
        return result;
    }
    
    int partition(vector<vector<int>> &points, int left, int right) {
        int wall, pivot;
        wall = left;
        pivot = right;
        
        for (int i = left; i < right; ++i) {
            if (getDistance(points[i]) <= getDistance(points[pivot])) {
                swap(points[i], points[wall]);
                wall++;
            }
        }
        
        swap(points[wall], points[pivot]);
        return wall;
    }
    
    int getDistance(vector<int> &a) {
        return ((a[0]*a[0])+(a[1]*a[1]));
    }
};