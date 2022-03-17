class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distances(n, INT_MAX), tempprices(n, 0);
        
        distances[src] = 0;
        
        for (int i = 0; i <= k; i++) {
            tempprices = distances;
            
            for (auto flight : flights) {
                if (distances[flight[0]] == INT_MAX) continue;
                
                if (distances[flight[0]] + flight[2] < tempprices[flight[1]]) {
                    tempprices[flight[1]] = distances[flight[0]] + flight[2];
                }
            }
            
            distances = tempprices;
        }
        return (distances[dst]==INT_MAX)?-1:distances[dst];
    }
};