#include <vector>

class Bank {
    vector<long long int> accbalances;
    int numaccounts;
public:
    Bank(vector<long long>& balance) {
        numaccounts = balance.size();
        accbalances.resize(numaccounts+1, 0);
        copy(balance.begin(), balance.end(), accbalances.begin()+1);
    }
    
    bool transfer(int account1, int account2, long long money) {
        // validations.
        if (!isValidAcc(account1) || !isValidAcc(account2)) return false;
        
        if (accbalances[account1] < money) return false;
        
        // processing.
        accbalances[account1] -= money;
        accbalances[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        //validations.
        if (!isValidAcc(account)) return false;
        
        accbalances[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        //validations.
        if (!isValidAcc(account)) return false;
        if(accbalances[account] < money) return false;
        
        accbalances[account] -= money;
        return true;
    }
    
    bool isValidAcc(int n) {
        return (n>=1 && n<=numaccounts);
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
