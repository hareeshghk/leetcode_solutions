#include <vector>

class ZigzagIterator {
    vector<int>::iterator s1,s2, e1,e2;
    bool turn;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        s1 = v1.begin();
        s2 = v2.begin();
        e1 = v1.end();
        e2 = v2.end();
        turn = true;
    }

    int next() {
        if (turn) {
            turn = !turn;
            if (s1 != e1) {
                return *(s1++);
            } else if(s2!=e2) {
                return *(s2++);
            }
            return -1;
        } else {
            turn = !turn;
            if (s2 != e2) {
                return *(s2++);
            } else if(s1!=e1) {
                return *(s1++);
            }
            return -1;
        }
    }

    bool hasNext() {
        if (s1 == e1 && s2== e2) return false;
        return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
