class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<int, int> counter;

        for (auto & point: points) {
            counter[point[1]]++;
        }

        vector<long long> c = vector<long long>(counter.size());
        int itr = 0;
        for (auto&e:counter) {
            long long val = e.second;
            c[itr++] = ((val * (val-1))/2) %1000000007;
        }

        long long answer = 0;

        for (int i = 1; i < c.size(); ++i) {
            answer = (answer+(c[i] * c[i-1])) % 1000000007;
            c[i] = (c[i]+c[i-1])%100000007;
        }
        return (int)answer;
    }
};