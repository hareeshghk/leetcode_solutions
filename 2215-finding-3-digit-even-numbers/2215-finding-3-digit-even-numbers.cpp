class Solution {
    vector<int> answer;
    vector<bool> used;
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        // unique integers
        // first element not zero
        // last element muset be even
        // there should be three digits
        sort(digits.begin(), digits.end());
        vector<int> current = vector<int>(3, 0);
        used = vector<bool>(digits.size(), false);
        findNumbers(0, digits, current);
        return answer;
    }
private:
    void findNumbers(int pos, vector<int> &d, vector<int> &c) {
        if (pos == 3) {
            answer.push_back(c[0]*100 + c[1]*10 + c[2]);
            return;
        }

        for (int i = 0; i < d.size(); ++i) {
            if (pos == 0 && d[i] == 0) continue;
            if (pos == 2 && d[i]%2 != 0) continue;
            if (used[i] == false) {
                used[i] = true;
                c[pos] = d[i];
                findNumbers(pos+1, d, c);
                used[i] = false;
                int j = i + 1;
                while (j < d.size() && d[j] == d[i]) {
                    j++;
                }
                i = j-1;
            }
        }
    }
};