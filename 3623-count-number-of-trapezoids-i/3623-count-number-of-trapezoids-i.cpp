class Solution {
    const int mod = 1000000007;
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> counter;
        for (auto & point: points) {
            counter[point[1]]++;
        }

        vector<long long> c = vector<long long>(counter.size());
        int itr = 0;
        long long val;
        for (auto& e:counter) {
            val = e.second;
            c[itr++] = ((val * (val-1))/2) %mod;
        }

        long long answer = 0;
        for (int i = 1; i < c.size(); ++i) {
            answer = (answer+(c[i] * c[i-1])) % mod;
            c[i] = (c[i]+c[i-1])%mod;
        }
        return (int)answer;
    }
};