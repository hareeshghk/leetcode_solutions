#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> nearsmalltoright, nearsmalltoleft;
        vector<int> nstr(n), nstl(n);
        nstr[n-1] = -1;
        for (int i =n-1; i >=0; i--) {
            while (!nearsmalltoright.empty() && heights[nearsmalltoright.top()] >= heights[i]) {
                nearsmalltoright.pop();
            }
            if (nearsmalltoright.empty()) {
                nstr[i] = -1;
            } else {
                nstr[i] = nearsmalltoright.top();
            }
            nearsmalltoright.push(i);
        }
        
        // for (int i = 0; i < n; i++) {
        //     cout << nstr[i] << " ";
        // }
        // cout << endl;
        
        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            while (!nearsmalltoleft.empty() && heights[nearsmalltoleft.top()] >= heights[i]) {
                nearsmalltoleft.pop();
            }
            if (nearsmalltoleft.empty()) {
                nstl[i] = -1;
            } else {
                nstl[i] = nearsmalltoleft.top();
            }
            nearsmalltoleft.push(i);
            
            int area = heights[i] * (1 + (nstl[i]==-1?i:i-nstl[i]-1)+(nstr[i]==-1?n-i-1:nstr[i]-i-1));
            maxarea = max(maxarea, area);
        }
        // for (int i = 0; i < n; i++) {
        //     cout << nstl[i] << " ";
        // }
        cout << endl;
        return maxarea;
    }
};
