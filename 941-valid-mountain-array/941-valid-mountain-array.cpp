#include <vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if (n<3) return false;
        int i = 1;
        while(i<n && arr[i-1]<arr[i]) i++;
        if (i==n||i==1) return false;
        while(i<n) {
            if (arr[i-1] > arr[i]) i++;
            else return false;
        }
        return true;
    }
};
