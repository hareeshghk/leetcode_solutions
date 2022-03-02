class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        unordered_map<int, double> q1, q2;
        q1[row*n+column] = 1.0;
        
        vector<vector<int>> dirs{{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
        int pos_x, pos_y, neighbour;
        double prob;
        while (k--) {
            for (auto val : q1) {
                pos_x = val.first/n;
                pos_y = val.first%n;
                prob = val.second;
                
                for (auto dir : dirs) {
                    if (isvalid(pos_x+dir[0], pos_y+dir[1], n)) {
                        neighbour = (pos_x+dir[0])*n+(pos_y+dir[1]);
                        if (q2.find(neighbour) != q2.end()) {
                            q2[neighbour] += prob/8;
                        } else {
                            q2[neighbour] = prob/8;
                        }
                    }
                }
            }
            q1 = q2;
            q2.clear();
        }
        
        double ans = 0.0;
        for (auto val : q1) {
            ans += val.second;
        }
        return ans;
    }
    
    bool isvalid(int i, int j, int n) {
        return (i>=0 && i <n && j>=0 && j<n);
    }
};