class Solution {
    int mod = 1000000007;
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<long long>> convMatrix = vector<vector<long long>>(26, vector<long long>(26, 0LL));

        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                convMatrix[i][(i+j)%26]++;
            }
        }

        vector<int> intitalCount = vector<int>(26, 0);

        for (auto ch : s) {
            intitalCount[ch-'a']++;
        }

        // Multiply convMatrix by t times and then  multiply it with initial count to get how many times each character in alphabets is repeated.
        convMatrix = multiply(convMatrix, t);

        long long answer = 0;

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                answer = (answer + (convMatrix[j][i] * intitalCount[j]))%mod;
            }
        }
        return (int)answer;
    }
private:
    vector<vector<long long>> multiplyMatrices(vector<vector<long long>> &a , vector<vector<long long>> &b) {
        vector<vector<long long>> c = vector<vector<long long>>(26, vector<long long>(26, 0));

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                int cursum = 0;
                for (int k = 0; k < 26; ++k) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j])%mod;
                }
            }
        }
        return c;
    }

    vector<vector<long long>> multiply(vector<vector<long long>> &convMatrix, int t) {
        vector<vector<long long>> result = vector<vector<long long>>(26, vector<long long>(26, 0));
        // making identity matrix.
        for (int i = 0; i < 26; ++i) {
            result[i][i] = 1;
        }

        while (t != 0) {
            if (t&1) {
               result = multiplyMatrices(result, convMatrix); 
            }

            t /= 2;
            convMatrix = multiplyMatrices(convMatrix, convMatrix);
        }
        return result;
    }
};