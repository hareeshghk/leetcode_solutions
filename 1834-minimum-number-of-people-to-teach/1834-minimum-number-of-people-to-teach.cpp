class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // better solution is this
        // consider friendships where new language is needed
        // in the rmeaining people with unsatisfied friendship, find the language which is know to max people and choose to teach taht to remaining people.
        int m = languages.size();
        auto unstisfiedFriendShips = unordered_set<int>();
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
                unstisfiedFriendShips.insert(fs[0]-1);
                unstisfiedFriendShips.insert(fs[1]-1);
            }
        }

        vector<int> languageCount = vector<int>(n,  0);
        int maxCount = 0;
        for (auto i : unstisfiedFriendShips) {
                for (auto& l : languages[i]) {
                    languageCount[l-1]++;
                    maxCount = max(maxCount, languageCount[l-1]);
                }
        }

        return unstisfiedFriendShips.size() - maxCount;
    }
};