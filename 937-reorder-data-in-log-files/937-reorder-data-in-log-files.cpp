#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

class Solution {
public:
    vector<string> temp;
    
    bool getVerdict(string &a, string &b) {
            auto x = a.substr(a.find(' ', 0)+1);
            auto y = b.substr(b.find(' ', 0)+1);
            
            auto is_x_digit = isdigit(x[0]);
            auto is_y_digit = isdigit(y[0]);
            if (!is_x_digit && !is_y_digit) {
                if (x==y) return a <= b;
                else return x<y;
            } else if (!is_x_digit && is_y_digit) {
                return true;
            } else if (is_x_digit && !is_y_digit) {
                return false;
            } else {
                return true;
            }
        }
    void merge(vector<string> &logs, int left,int mid, int right) {
        int i = left, j = mid+1, k= 0;
        
        while (i <= mid && j <=right) {
            if (getVerdict(logs[i], logs[j])) {
                temp[k++]=logs[i++];
            } else {
                temp[k++]=logs[j++];
            }
        }
        
        while(i <= mid) {
            temp[k++] = logs[i++];
        }
        
        while(j <= right) {
            temp[k++] = logs[j++];
        }
        
        for (int i = 0; i < k; ++i) {
            logs[left+i] = temp[i];
        }
    }
    
    void mergesort(vector<string> &logs, int left, int right) {
        if (left >= right) return;
        
        int mid = left+ (right-left)/2;
        
        mergesort(logs, left, mid);
        mergesort(logs, mid+1, right);
        merge(logs, left, mid, right);
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        temp.resize(logs.size());
        mergesort(logs, 0, logs.size()-1);
        return logs;
    }
};
