class NumMatrix {
    int rows, cols;
    vector<vector<int>> store;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        store.resize(rows+1, vector<int>(cols+1, 0));
        buildBIT(matrix);
    }
    
    int lsb(int n) {
        return n&(-n);
    }
    
    void buildBIT(vector<vector<int>>& matrix) {
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                updateBIT(i, j, matrix[i-1][j-1]);
            }
        }
    }
    
    void updateBIT(int row, int col, int val) {
        for (int i = row; i <= rows; i += lsb(i)) {
            for (int j = col; j <= cols; j+= lsb(j)) {
                store[i][j] += val;
            }
        }
    }
    
    int queryBIT(int row, int col) {
        if ((row <=0 || row > rows) ||(col <=0 || col > cols)) return 0;
        
        int result = 0;
        for (int i = row; i > 0; i-=lsb(i)) {
            for (int j = col; j > 0; j-=lsb(j)) {
                result += store[i][j];
            }
        }
        return result;
    }
    
    int sumRegionBIT(int row1, int col1, int row2, int col2) {
        int v1 = queryBIT(row2, col2);
        int v2 = queryBIT(row1-1, col1-1);
        int v3 = queryBIT(row2, col1-1);
        int v4 = queryBIT(row1-1, col2);
        
        return (v1+v2)-(v3+v4);
    }
    
    void update(int row, int col, int val) {
        row++;
        col++;
        
        int current_val = sumRegionBIT(row, col, row, col);
        
        int diff = val-current_val;
        updateBIT(row, col, diff);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;col1++;row2++;col2++;
        return sumRegionBIT(row1, col1, row2, col2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */