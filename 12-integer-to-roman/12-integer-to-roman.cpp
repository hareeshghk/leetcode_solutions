#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        
        ans += thousands(num);
        num = num%1000;
        ans += hundreds(num);
        num = num%100;
        ans += tens(num);
        num = num%10;
        ans += ones(num);
        
        return ans;
    }
    
    string thousands(int n) {
        n = n/1000;
        
        string s(n, 'M');
        return s;
    }
    
    string hundreds(int n) {
        n = n/100;
        
        if (n==4) {
            return "CD";
        } else if (n==9) {
            return "CM";
        } else if (n>=5) {
            return "D"+string(n-5, 'C');
        } else {
            return string(n, 'C');
        }
    }
    
    string tens(int n) {
        n = n/10;
        
        if (n==4) {
            return "XL";
        } else if (n==9) {
            return "XC";
        } else if (n>=5) {
            return "L"+string(n-5, 'X');
        } else {
            return string(n, 'X');
        }
    }
    
    string ones(int n) {
        if (n==4) {
            return "IV";
        } else if (n==9) {
            return "IX";
        } else if (n>=5) {
            return "V"+string(n-5, 'I');
        } else {
            return string(n, 'I');
        }
    }
};
