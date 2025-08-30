#include <algorithm>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        // ways(high) - ways(low-1)

        // high max is 10^4 so we are looking at two digit and four digit numbers.

        /// get all possible ones and sort them and then binary search to find how many.
        // or enumerate aff numbers since limits given are small.
        int answer = 0;
        for (int i = low; i <= high; ++i) {
            if (i < 100 && i%11 == 0) answer++;
            if (i >= 1000 && i < 10000) {
                int left = (i/1000) + ((i%1000)/100);
                int right = ((i%100)/10)+(i%10);

                if (left == right) answer++;
            }
        }
        return answer;
    }
};
