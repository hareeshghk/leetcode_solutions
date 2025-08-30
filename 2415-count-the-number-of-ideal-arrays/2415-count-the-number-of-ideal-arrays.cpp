#include <algorithm>
#include <vector>

class Solution {
    int modVal = 1000000007;
    int maxp = 1;
    vector<vector<int>> primeFactors;
    vector<vector<int>> combinations;
public:
    int idealArrays(int n, int maxValue) {
        initializePrimeFactors(maxValue); 
        initializeCombinations(n, maxp);
        long long answer = 0;
        // Iterate over n'th value
        for (int i = 1; i <= maxValue; ++i) {
            long long temp = 1;
            for (int p : primeFactors[i]) {
                temp = (temp * getCombinations(n+p-1, p))%modVal;
            }
            answer = (answer + temp) % modVal;
        }
        return answer;
    }
private:
    void initializePrimeFactors(int val) {
        vector<int> seive = vector<int>(val+1, 0);
        for (int j = 2; j <= val; ++j) {
            if (seive[j] == 0) {
                for (int k = j; k <= val; k+= j) {
                    seive[k] = j;
                }
            }
        }

        primeFactors = vector<vector<int>>(val+1, vector<int>());
        int primefactorcount = 0;
        for (int i = 2; i <= val; ++i) {
            primefactorcount = 0;
            int x = i;
            while (x > 1) {
                int p = seive[x];
                int cnt = 0;
                while (x%p ==0) {
                    x /= p;
                    cnt++;
                }
                primeFactors[i].push_back(cnt);
                primefactorcount += cnt;
            }
            maxp = max(maxp, primefactorcount);
        }
    }

    void initializeCombinations(int n, int p) {
        combinations = vector<vector<int>>(n+p+1, vector<int>(p+1, 0));
        combinations[0][0] = 1;
        for (int i = 1; i <= (n+p); ++i) {
            combinations[i][0] = 1;
            for (int j = 1; j <= p; ++j) {
                combinations[i][j] = (combinations[i-1][j] + combinations[i-1][j-1]) % modVal;
            }
        }
    }

    int getCombinations(int a, int b) {
        return combinations[a][b];
    }
};
