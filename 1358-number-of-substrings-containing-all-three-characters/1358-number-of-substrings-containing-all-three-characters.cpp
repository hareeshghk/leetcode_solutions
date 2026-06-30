class Solution {
public:
    int numberOfSubstrings(string s) {
        int a_latest_positition = -1, b_latest_positition = -1, c_latest_positition = -1;
        int answer = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a') {
                a_latest_positition = i;
            } else if (s[i] == 'b') {
                b_latest_positition = i;
            } else {
                c_latest_positition = i;
            }

            answer += 1 + min(a_latest_positition, min(b_latest_positition, c_latest_positition));
        }

        return answer;
    }
};