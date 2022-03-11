class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1idx = num1.size()-1;
        int num2idx = num2.size()-1;
        
        string ans;
        
        int sum, carry = 0;
        while(num1idx >=0 && num2idx>=0) {
            sum = (num1[num1idx]-'0') + (num2[num2idx]-'0') + carry;
            carry = sum/10;
            sum = sum%10;
            ans += (char) (sum+'0');
            num1idx--;
            num2idx--;
        }
        
        while (num1idx >=0) {
            sum = (num1[num1idx]-'0') + carry;
            carry = sum/10;
            sum = sum%10;
            ans += (char) (sum+'0');
            num1idx--;
        }
        
        while (num2idx >=0) {
            sum = (num2[num2idx]-'0') + carry;
            carry = sum/10;
            sum = sum%10;
            ans += (char) (sum+'0');
            num2idx--;
        }
        
        if (carry != 0) {
            ans += (char)(carry+'0');
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};