class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        for (int i = 0; i < s.length(); ++i) {
            int d = distance[s[i] - 'a'];

            int leftIndex = i - (d+1);
            int rightIndex = i + (d+1);

            if (leftIndex >= 0 && s[leftIndex] == s[i]) {
                continue;
            }

            if (rightIndex < s.length() && s[rightIndex] == s[i]) {
                continue;
            }
            return false;
        }
        return true;
    }
};