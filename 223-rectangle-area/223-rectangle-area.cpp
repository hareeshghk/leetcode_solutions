#include <algorithm>

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a_area = (ax2-ax1)*(ay2-ay1);
        int b_area = (bx2-bx1)*(by2-by1);
        
        if (ax2 < bx1 || bx2<ax1 || ay2<by1 ||by2<ay1) return a_area+b_area;
        
        int a,b,c,d;
        a = max(ax1,bx1); b=min(ax2,bx2);c=max(ay1,by1);d=min(ay2,by2);
        return a_area+b_area-((b-a)*(d-c));
    }
};
