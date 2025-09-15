class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int answer = 0;

        unordered_set<char> broken = unordered_set<char>();

        for (char ch : brokenLetters) {
            broken.insert(ch);
        } 

        for (int i = 0; i < text.size(); ++i) {
            int j = i;
            bool canbeTyped = true;
            while (j < text.size() && text[j] != ' ') {
                if (broken.find(text[j]) != broken.end()) {
                    canbeTyped = false;
                }
                j++;
            }
            if (canbeTyped) {
                ++answer;
            }
            i = j;
        }

        return answer;
    }
};