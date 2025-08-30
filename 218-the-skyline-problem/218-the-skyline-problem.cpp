#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Node {
public:
    int x, h;
    bool is_start;
    Node(int s, int height, bool b) {
        x = s;
        h = height;
        is_start = b;
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Node> inputPoints;
        
        for (auto building : buildings) {
            inputPoints.push_back(Node(building[0], building[2], true));
            inputPoints.push_back(Node(building[1], building[2], false));
        }
        
        sort(inputPoints.begin(), inputPoints.end(), [](Node &a, Node &b){
            if (a.x < b.x) return true;
            
            if(a.x > b.x) return false;
            
            if (a.is_start && b.is_start) {
                return a.h > b.h;
            }
            
            if (a.is_start && !b.is_start) {
                return true;
            }
            
            if (!a.is_start && b.is_start) {
                return false;
            }
            
            return a.h < b.h;
        });
        
        map<int,int> counter;
        counter[0] = 1;

        vector<vector<int>> result;
        int prevMax = 0, currentmax;
        for (int i = 0; i < inputPoints.size(); ++i) {
            auto node = inputPoints[i];
            
            if (node.is_start) {
                counter[node.h]++;
            } else {
                counter[node.h]--;
                
                if (counter[node.h] == 0) {
                    counter.erase(node.h);
                }
            }
            
            currentmax = counter.rbegin()->first;
            
            if (currentmax != prevMax) {
                result.push_back({node.x, currentmax});
                prevMax = currentmax;
            }
        }
        
        return result;
    }
};
