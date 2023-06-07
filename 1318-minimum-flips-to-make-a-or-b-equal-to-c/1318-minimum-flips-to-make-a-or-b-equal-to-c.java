class Solution {
    public int minFlips(int a, int b, int c) {
        int ops = 0;
        
        int abit, bbit,cbit;
        for (int i = 0; i < 32; ++i) {
            abit = a&1;
            bbit = b&1;
            cbit = c&1;
            
            if ((abit | bbit) != cbit) {
                if (cbit == 1) {
                    ++ops;
                } else {
                    ops += abit+bbit;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        
        return ops;
    }
}