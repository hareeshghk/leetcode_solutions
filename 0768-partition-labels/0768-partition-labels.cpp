class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_occurrence = vector<int>(26, -1);
        for (int i = 0; i < s.length(); ++i) {
            last_occurrence[s[i]-'a'] = i;
        }

        int start = 0;
        int end = 0;
        vector<int> answer;
        for (int i = 0; i < s.length(); ++i) {
            end = max(end, last_occurrence[s[i]-'a']);

            if (i == end) {
                answer.push_back((end-start)+1);
                start = i+1;
                end = i+1;
            }
        }
        return answer;
    }
};