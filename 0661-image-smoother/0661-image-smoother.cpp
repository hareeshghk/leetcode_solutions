class Solution {
    vector<vector<int>> dirs {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
    int rows, cols;
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        rows = img.size();
        cols = img[0].size();
        
        vector<vector<int>> result = vector<vector<int>>(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = getavg(img, i, j);
            }
        }
        return result;
    }
    
    int getavg(const vector<vector<int>>& img, int i, int j) {
        int numvalues = 0;
        int totalsum = 0;
        int x, y;
        for (auto dir : dirs) {
            x = i + dir[0];
            y = j + dir[1];
            
            if (x>=0 && x < rows && y >=0 && y < cols) {
                totalsum += img[x][y];
                numvalues++;
            }
        }
        return totalsum/numvalues;
    }
};