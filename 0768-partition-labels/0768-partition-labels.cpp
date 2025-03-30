class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last_occurrence;
        for (int i = 0; i < s.length(); ++i) {
            last_occurrence[s[i]] = i;
        }

        int start = 0;
        int end = 0;
        vector<int> answer;
        for (int i = 0; i < s.length(); ++i) {
            end = max(end, last_occurrence[s[i]]);

            if (i == end) {
                answer.push_back((end-start)+1);
                start = i+1;
                end = i+1;
            }
        }
        return answer;
    }
};