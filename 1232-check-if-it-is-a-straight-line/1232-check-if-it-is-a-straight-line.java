class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int slopeNum, slopeDen;
        
        int n = coordinates.length;
        
        if (n <= 2) return true;
        
        slopeNum = coordinates[1][1]-coordinates[0][1];
        slopeDen = coordinates[1][0]-coordinates[0][0];
        
        int g = gcd(slopeNum, slopeDen);
        
        slopeNum = slopeNum/g;
        slopeDen = slopeDen/g;
        
        Arrays.sort(coordinates, (a, b) -> a[0]-b[0]);
        
        for (int i = 1; i < n; ++i) {
            int nslopeNum = coordinates[i][1]-coordinates[i-1][1];
            int nslopeDen = coordinates[i][0]-coordinates[i-1][0];
            int ng = gcd(nslopeNum, nslopeDen);
            
            nslopeNum /= ng;
            nslopeDen /= ng;
            
            if (nslopeNum != slopeNum || nslopeDen != slopeDen) {
                return false;
            }
        }
        return true;
    }
    
    private int gcd(int a, int b) {
        int temp;
        while (a != 0) {
            temp = a;
            a = b%a;
            b = temp;
        }
        return b;
    }
}