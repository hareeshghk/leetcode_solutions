class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [](vector<int> &a, vector<int> &b) {return a[1] < b[1];});

        int answer = 0;
        for (int i = 0; i < n; ++i) {
            answer = max(answer, events[i][2]);

            int j = findFirstIndex(events, i-1, events[i][0]);

            if (j != -1) {
                answer = max(answer, events[j][2] + events[i][2]);
            }

            if (i != 0) events[i][2] = max(events[i][2], events[i-1][2]);
        }
        return answer;
    }
private:
    int findFirstIndex(vector<vector<int>> &events, int index, int val) {
        int left = 0, right = index;
        int answer = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (events[mid][1] < val) {
                answer = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return answer;
    }
};