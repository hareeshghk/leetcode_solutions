#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> store;
        
        int ws = 0;
        int result= 0;
        for (int we  = 0; we < fruits.size(); ++we) {
            store[fruits[we]]++;
            
            while (store.size() > 2) {
                store[fruits[ws]]--;
                if (store[fruits[ws]] == 0) {
                    store.erase(fruits[ws]);
                }
                ws++;
            }
            result = max(result, we-ws+1);
        }
        return result;
    }
};
