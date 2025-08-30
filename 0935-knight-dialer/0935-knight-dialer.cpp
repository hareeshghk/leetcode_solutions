#include <vector>
using namespace std;

class Solution {
public:
    const int mod = 1000000007;
    int knightDialer(int n) {
        if (n==1) return 10;
        
        vector<vector<long>> m = vector<vector<long>>(12, vector<long>(12, 0));
        
        m[0][5] = 1;m[0][7] =1;
        m[1][6] = 1; m[1][8] = 1;
        m[2][3] =1; m[2][7] = 1;
        m[3][2]=1;m[3][8]=1;m[3][10]=1;
        m[5][0]=1;m[5][6]=1;m[5][10]=1;
        m[6][1]=1;m[6][5]=1;
        m[7][0]=1;m[7][2]=1;
        m[8][1]=1;m[8][3]=1;
        m[10][3]=1;m[10][5]=1;
        
        m = multiply(m, n-1);
        
        return multiplyAndSumColumns(m, {{1},{1},{1},{1},{1},{1},{1},{1},{1},{0},{1},{0}});
    }
    
    vector<vector<long>> multiply(vector<vector<long>> &m, int exp) {
        int length = m.size();
        vector<vector<long>> result = vector<vector<long>>(length, vector<long>(length, 0));
        for (int i = 0; i < length; ++i) {
            result[i][i] = 1;
        }
        
        while (exp != 0) {
            if (exp & 1) {
                result = multiplyMatrix(result, m);
            }
            
            exp /= 2;
            m = multiplyMatrix(m, m);
        }
        return result;
    }
    
    int multiplyAndSumColumns(vector<vector<long>> &m, vector<vector<long>> vals) {
        auto result = multiplyMatrix(m, vals);
        
        int answer = 0;
        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < result[i].size(); ++j) {
                answer = (answer + result[i][j])%mod;
            }
        }
        return answer;
    }
    
    vector<vector<long>> multiplyMatrix(vector<vector<long>> &a, vector<vector<long>> &b) {
        int finalRows = a.size();
        int finalColumns = b[0].size();
        
        vector<vector<long>> result = vector<vector<long>>(finalRows, vector<long>(finalColumns, 0));
        
        for (int i = 0; i < finalRows; ++i) {
            for (int j = 0; j < finalColumns; ++j) {
                for (int k = 0; k < b.size(); ++k) {
                    result[i][j] = (result[i][j] + (a[i][k] * b[k][j]))%mod;
                }
            }
        }
        
        return result;
    }
};
