class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        int i = 0;

        vector<string> answer;

        while (i + k -1 < n) {
            answer.push_back(s.substr(i, k));
            i += k;
        }

        if (i == n) return answer;

        string extra = s.substr(i);

        string filling = string(k-extra.length(), fill);

        answer.push_back(extra+filling);
        return answer;
    }
};