class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<vector<int>> pos(n, vector<int>(2, 0));
        vector<int> ans;
        int cummulative_seats = 0;
        for (auto booking : bookings) {
            pos[booking[0]-1][0]+=booking[2];
            pos[booking[1]-1][1]-=booking[2];
        }
        
        for (int i = 0; i < n; i++) {
            cummulative_seats += pos[i][0];
            ans.push_back(cummulative_seats);
            cummulative_seats += pos[i][1];
        }
        return ans;
    }
};