class Solution {
public:
    int pivotInteger(int n) {
        auto s = sqrt((n * (n+1)) / 2);

        if (ceil(s) == floor(s))  return (int)s;
        return -1;
    }
};

