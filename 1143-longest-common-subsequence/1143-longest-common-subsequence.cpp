#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> lcs(m+1, vector<int>(n+1, 0));
        
        for (int i = 1; i<= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    lcs[i][j] = lcs[i-1][j-1]+1;
                } else {
                    lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
                }
            }
        }
        // print subsequence in rev order;
        // int i = m;
        // int j = n;
        // for (int k = 0; k < lcs[m][n]; k++) {
        //     if (text1[i-1] == text2[j-1]) {
        //         cout << text1[i-1];
        //         i = i-1;
        //         j = j-1;
        //     } else {
        //         if (lcs[i][j] == lcs[i][j-1]) {
        //             cout << text2[j-1];
        //             j = j-1;
        //         } else {
        //             cout << text1[i-1];
        //             i = i - 1;
        //         }
        //     }
        // }
        cout << endl;
        return lcs[m][n];
    }
};
