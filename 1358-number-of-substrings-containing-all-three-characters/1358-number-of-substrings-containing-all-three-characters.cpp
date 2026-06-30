class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> char_positions = vector<int>(3, -1);
        int answer = 0;

        for (int i = 0; i < s.length(); ++i) {
            char_positions[s[i]-'a'] = i;

            answer += 1 + min(char_positions[0], min(char_positions[1], char_positions[2]));
        }

        return answer;
    }
};