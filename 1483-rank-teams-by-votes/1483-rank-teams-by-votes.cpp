class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int positions = votes[0].length();

        vector<vector<int>> votePriority = vector<vector<int>>(26, vector<int>(positions+1, 0));

        for (int i = 0; i < 26; ++i) {
            votePriority[i][positions] = 26-i;
        }
        
        for (auto& vote : votes) {
            for (int i = 0; i < positions; ++i) {
                votePriority[vote[i]-'A'][i]++;
            }
        }

        // sorting the vote priority.
        sort(votePriority.begin(), votePriority.end(), [positions](vector<int> &a, vector<int> &b){
            for (int i = 0; i <= positions; ++i) {
                if (a[i] > b[i]) return true;
                if (a[i] < b[i]) return false;
            }
            return false;
        });

        string answer = "";

        for (int i = 0; i < positions; ++i) {
            answer += ('A' + (26-votePriority[i][positions]));
        }
        return answer;
    }
};