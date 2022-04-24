class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct fartherPoint {
            bool operator()(vector<int> &x, vector<int> &y) {
                return (x[0]*x[0] + x[1]*x[1]) > (y[0]*y[0] + y[1]*y[1]);
            }
        };
        
        make_heap(points.begin(), points.end(), fartherPoint());
        
        vector<vector<int>> result;
        
        while (k--) {
            result.push_back(points[0]);
            pop_heap(points.begin(), points.end(), fartherPoint());
            points.pop_back();
        }
        return result;
    }
};