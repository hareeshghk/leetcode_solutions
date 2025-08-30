#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        // assuming logs are alreay in corrected sorted order
        vector<int> timings(n, 0);
        
        stack<vector<int>> st;
        stack<int> levelvalue;
        
        int prev_range_size = 0;

        for (auto& log : logs) {
            auto parsed = GetDetails(log);
            // Print(parsed);
            if (parsed[1] == 0) {
                st.push(parsed);
                levelvalue.push(0);
            } else {
                auto prev_start_range = st.top();
                st.pop();
                prev_range_size = levelvalue.top();
                levelvalue.pop();
                timings[parsed[0]] += (parsed[2]-prev_start_range[2]+1)-prev_range_size;
                if (!levelvalue.empty()) {
                    auto prevlevel = levelvalue.top();
                    levelvalue.pop();
                    prevlevel += parsed[2]-prev_start_range[2]+1;
                    levelvalue.push(prevlevel);
                }
            }
        }
        return timings;
    }
    
    void Print(vector<int> &a) {
        cout << a[0] << " " << a[1] << " " << a[2] << endl;
    }
    
    // vector has 3 datails function id, state 0/1(start/end), time
    vector<int> GetDetails(string &s) {
        int start, end = 0;
        string temp;
        
        vector<int> result;
        
        // fist token function id
        start = s.find_first_not_of(':', end);
        end = s.find(':', start);
        temp = s.substr(start, end-start);
        result.push_back(stoi(temp));
        
        // second token
        start = s.find_first_not_of(':', end);
        end = s.find(':', start);
        temp = s.substr(start, end-start);
        if (temp[0] == 's') {
            result.push_back(0);
        } else {
            result.push_back(1);
        }
        
        // third token
        start = s.find_first_not_of(':', end);
        end = s.find(':', start);
        temp = s.substr(start, end-start);
        result.push_back(stoi(temp));
        
        return result;
    }
};
