class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // brute foirce
        // pick each language to teach and check if that solves the answer and store how many people you had to teach that.
        // min of each language count is the answer.

        // better solution is this/
        // consider friendships where new language is needed
        // in the rmeaining people with unsatisfied friendship, find the language which is know to max people and choose to teach taht to remaining people.
        int m = languages.size();
        vector<int> unstisfiedFriendShips = vector<int>(m, 0);
        for (auto& fs : friendships) {
            // check if friendshsip satisfied fs[0] and fs[1] languages if not add count to both.
            auto l1 = languages[fs[0]-1];
            auto s1 = unordered_set<int>(l1.begin(), l1.end());
            auto fsFound = false;
            for (auto x : languages[fs[1]-1]) {
                if (s1.find(x) != s1.end()) {
                    fsFound = true;
                    break;
                }
            }

            if (!fsFound) {
                unstisfiedFriendShips[fs[0]-1]++;
                unstisfiedFriendShips[fs[1]-1]++;
            }
        }

        vector<int> languageCount = vector<int>(n,  0);
        int neededLearning = 0;
        for (int i = 0; i < m; ++i) {
            if (unstisfiedFriendShips[i] != 0) {
                neededLearning++;
                for (auto& l : languages[i]) {
                    languageCount[l-1]++;
                }
            }
        }

        sort(languageCount.begin(), languageCount.end());

        return neededLearning-languageCount[n-1];
    }
};