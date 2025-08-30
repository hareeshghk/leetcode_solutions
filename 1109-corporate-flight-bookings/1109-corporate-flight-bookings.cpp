#include <vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> pos(n+1, 0);
        vector<int> ans;
        
        // fillling array on when to add extra seats when to delete them.
        // add seats if booking started on that flight.
        // remove seats if booking ended on that day.
        for (auto booking : bookings) {
            pos[booking[0]-1] += booking[2];
            pos[booking[1]] -= booking[2];
        }
        
        // seats count till now.
        int cummulative_seats = 0;
        
        for (int i = 0; i < n; i++) {
            cummulative_seats += pos[i];
            ans.push_back(cummulative_seats);
        }
        return ans;
    }
};
