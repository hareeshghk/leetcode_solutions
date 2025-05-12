class Solution {
    vector<int> answer;
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        // unique integers
        // first element not zero
        // last element muset be even
        // there should be three digits
        vector<int> counter = vector<int>(10, 0);
        for (int i = 0; i < digits.size(); ++i) {
            counter[digits[i]]++;
        }
        vector<int> current = vector<int>(3, 0);
        findNumbers(0, counter, current);
        return answer;
    }
private:
    void findNumbers(int pos, vector<int> &d, vector<int> &c) {
        if (pos == 3) {
            answer.push_back(c[0]*100 + c[1]*10 + c[2]);
            return;
        }

        for (int i = 0; i < 10; ++i) {
            if (pos == 0 && i == 0) continue;
            if (pos == 2 && i%2 != 0) continue;
            if (d[i] > 0) {
                d[i]--;
                c[pos] = i;
                findNumbers(pos+1, d, c);
                d[i]++;
            }
        }
    }
};