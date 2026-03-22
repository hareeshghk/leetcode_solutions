class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // after 90 degrees i, j elemenet(nxn matrix) goes to j, n-1-i index
        // second rotation j, n-1-i goes to n-1-i, n-1-j
        // third rorartion n-1-i, n-1-j goes to n-1-j, i 

        vector<function<pair<int, int>(int, int)>> rotationFunc;
        int n = mat.size();

        rotationFunc.push_back([n](int a, int b) {
            return pair<int, int>(a, b);
        });

        rotationFunc.push_back([n](int a, int b) {
            return pair<int, int>(b, n-1-a);
        });

        rotationFunc.push_back([n](int a, int b) {
            return pair<int, int>(n-1-a, n-1-b);
        });

        rotationFunc.push_back([n](int a, int b) {
            return pair<int, int>(n-1-b, a);
        });

        for (int k = 0; k < rotationFunc.size(); ++k) {
            bool isMatching = true;

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    auto p = rotationFunc[k](i, j);
                    if (mat[i][j] != target[p.first][p.second]) {
                        isMatching = false;
                    }
                }
            }

            if (isMatching) {
                return true;
            }
        }

        return false;
    }
};