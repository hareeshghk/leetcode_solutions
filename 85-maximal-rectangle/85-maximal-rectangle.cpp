#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> dp(n, 0);
        
        int maxarea = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[j] = ((matrix[i][j] == '1')?(dp[j] + 1):0);
            }
            maxarea = max(maxarea, findmaxrectareainhistogram(dp));
        }
        return maxarea;
    }
private:
    int findmaxrectareainhistogram(vector <int> &arr) {
        int n = arr.size();
        
        stack<int> st;
        
        int maxarea = 0;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                int curtop = st.top();
                st.pop();
                maxarea = max(maxarea, (arr[curtop] * ((st.empty())?(i):(i - st.top() - 1))));
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            int curtop = st.top();
            st.pop();
            maxarea = max(maxarea, arr[curtop] * (st.empty()?n:(n-1-st.top())));
        }
        return maxarea;
    }
};
