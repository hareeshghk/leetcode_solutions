class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> counter;

        for (auto ch : magazine) {
            counter[ch]++;
        }

        for (auto ch : ransomNote) {
            if (counter.find(ch) == counter.end() || counter[ch] == 0) return false;
            counter[ch]--;
        }

        return true;
    }
};