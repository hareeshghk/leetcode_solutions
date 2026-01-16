class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> hdiffs;
        for (int i = 0; i < hFences.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                hdiffs.insert(hFences[i]-hFences[j]);
            }
        }

        long long maxDiff = 0;
        long long diff;
        const int mod = 1000000007;
        for (int i = 0; i < vFences.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                diff = vFences[i]-vFences[j];

                if (hdiffs.find(diff) != hdiffs.end()) {
                    maxDiff = max(maxDiff, diff);
                }
            }
        }

        if (maxDiff == 0) return -1;


        return (maxDiff * maxDiff) %mod;
    }
};