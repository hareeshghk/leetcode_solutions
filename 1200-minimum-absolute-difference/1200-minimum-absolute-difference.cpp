class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        int diff;
        vector<vector<int>> answer;

        for (int i = 1; i < arr.size(); ++i) {
            diff = arr[i]-arr[i-1];

            if (diff < minDiff) {
                answer = vector<vector<int>>();
                minDiff = diff;
                answer.push_back({arr[i-1], arr[i]});
            } else if (diff == minDiff) {
                answer.push_back({arr[i-1], arr[i]});
            }
        }

        return answer;
    }
};