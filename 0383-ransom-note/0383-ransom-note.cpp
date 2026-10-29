class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int counter[26] = {0};

        for (auto ch : magazine) {
            counter[ch-'a']++;
        }

        for (auto ch : ransomNote) {
            if (counter[ch-'a'] == 0) return false;
            counter[ch-'a']--;
        }

        return true;
    }
};