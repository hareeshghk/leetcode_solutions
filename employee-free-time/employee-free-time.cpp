#include <algorithm>
#include <vector>

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int num_employees = schedule.size();
        
        vector<vector<Interval>> freeslots(num_employees, vector<Interval>());
        
        int counter = 0;
        for (auto sched : schedule) {
            if (sched.size() == 0) {
                freeslots[counter++] = vector<Interval>{Interval(INT_MIN, INT_MAX)};
                continue;
            }
            
            freeslots[counter].push_back(Interval{INT_MIN, sched[0].start});
            
            for (int i = 1; i < sched.size(); ++i) {
                freeslots[counter].push_back(Interval{sched[i-1].end, sched[i].start});
            }
            
            freeslots[counter].push_back(Interval{sched[sched.size()-1].end, INT_MAX});
            counter++;
        }
        
        
        vector<Interval> duplicates = freeslots[0];
        vector<Interval> nextduplicates;
        
        for (int i = 1; i < num_employees; ++i) {
            int m = duplicates.size();
            int n = freeslots[i].size();
            
            int j=0,k=0;
            
            while (j<m && k < n) {
                if (duplicates[j].end <= freeslots[i][k].start) {
                    j++;
                } else if (freeslots[i][k].end <= duplicates[j].start) {
                    k++;
                } else {
                    nextduplicates.push_back(Interval(max(duplicates[j].start, freeslots[i][k].start), min(duplicates[j].end, freeslots[i][k].end)));
                    if (duplicates[j].end < freeslots[i][k].end) {
                        j++;
                    } else if (duplicates[j].end > freeslots[i][k].end) {
                        k++;
                    } else {
                        j++;k++;
                    }                     
                }
            }
            duplicates = nextduplicates;
            
            // for (auto d : duplicates) {
            //     cout << d.start << " " << d.end << endl;
            // }
            nextduplicates.clear();
        }
        
        if (duplicates.size() == 0) return duplicates;
        
        if (duplicates[duplicates.size()-1].end == INT_MAX) duplicates.pop_back();
        
        if (duplicates[0].start == INT_MIN) duplicates.erase(duplicates.begin());
        
        return duplicates;
    }
};
