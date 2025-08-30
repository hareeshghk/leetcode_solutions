#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<vector<int>> dp;
    int numberOfPatterns(int m, int n) {
        graph[0] = {5,7};graph[1]={6,8};graph[2]={3,7};
        graph[3] = {2,8};graph[4]={};graph[5]={0,6};
        graph[6] = {1,5};graph[7]={0,2};graph[8]={1,3};
        
        if (m>n) return 0;
        
        int a = numner_of_patterns_with_k_keys(n);
        int b = numner_of_patterns_with_k_keys(m-1);
        
        // cout << a << " " << b << endl;
        return a-b;
    }
    
    int numner_of_patterns_with_k_keys(int k) {
        dp.clear();
        dp.resize(9, vector<int>(1<<9, -1));
        int result = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result += backtrack(i*3+j, k-1, 1<<(i*3+j));
            }
        }
        return result;
    }
    
    int backtrack(int pos, int k, int mask) {
        if (k<0) return 0;
        
        if (k==0) return 1;
        
        if (dp[pos][mask] != -1) return dp[pos][mask];
        
        int x = pos/3;
        int y = pos%3;
        int result = 1;
        
        int newpos;
        
        // horizontal
        for (int i = 1; i < 3; ++i) {
            newpos = x*3+y+i;
            if (y+i < 3 && ((mask & (1<<newpos)) == 0)) {
                result += backtrack(newpos, k-1, mask|(1<<newpos));
                break;
            }
        }
        
        for (int i = 1; i < 3; ++i) {
            newpos = x*3+y-i;
            if (y-i >= 0 && ((mask & (1<<newpos)) == 0)) {
                result += backtrack(newpos, k-1, mask|(1<<newpos));
                break;
            }
        }
        
        // vertical
        for (int i = 1; i < 3; ++i) {
            newpos = (x+i)*3+y;
            if (x+i < 3 && ((mask & (1<<newpos)) == 0)) {
                result += backtrack(newpos, k-1, mask|(1<<newpos));
                break;
            }
        }
        
        for (int i = 1; i < 3; ++i) {
            newpos = (x-i)*3+y;
            if (x-i >= 0 && ((mask & (1<<newpos)) == 0)) {
                result += backtrack(newpos, k-1, mask|(1<<newpos));
                break;
            }
        }
        
        // left to right diagonal
        for (int i = 1; i < 3; ++i) {
            newpos = (x+i)*3+y-i;
            if (x+i < 3 && y-i >=0 && ((mask & (1<<newpos)) == 0)) {
                result += backtrack(newpos, k-1, mask|(1<<newpos));
                break;
            }
        }
        
        for (int i = 1; i < 3; ++i) {
            newpos = (x-i)*3+y+i;
            if (x-i >= 0 && y+i < 3 && ((mask & (1<<newpos)) == 0)) {
                result += backtrack(newpos, k-1, mask|(1<<newpos));
                break;
            }
        }
        
        // right to left diagonal
        for (int i = 1; i < 3; ++i) {
            newpos = (x+i)*3+y+i;
            if (x+i < 3 && y+i < 3 && ((mask & (1<<newpos)) == 0)) {
                result += backtrack(newpos, k-1, mask|(1<<newpos));
                break;
            }
        }
        
        for (int i = 1; i < 3; ++i) {
            newpos = (x-i)*3+y-i;
            if (x-i >= 0 && y-i >= 0 && ((mask & (1<<newpos)) == 0)) {
                result += backtrack(newpos, k-1, mask|(1<<newpos));
                break;
            }
        }
        
        // random
        for (auto nei : graph[pos]) {
            if ((mask & (1<<nei)) == 0) {
                result += backtrack(nei, k-1, mask|(1<<nei));
            }
        }
        
        dp[pos][mask] = result;
        return result;
    }
};
