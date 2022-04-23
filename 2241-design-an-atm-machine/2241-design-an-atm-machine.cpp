class ATM {
    vector<long long int> counts;
    vector<int> denominations;
public:
    ATM() {
        counts.resize(5, 0);
        denominations.resize(5, 0);
        denominations[0] = 20;
        denominations[1] = 50;
        denominations[2] = 100;
        denominations[3] = 200;
        denominations[4] = 500;
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) {
            counts[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> result(5, 0);
        for (int i = 4; i >=0; --i) {
            if (counts[i] == 0) continue;
            long long int num_notes = min(counts[i], (long long int)amount/denominations[i]);
            result[i] += num_notes;
            counts[i] -= num_notes;
            amount -= num_notes*denominations[i];
        }
        
        if (amount == 0) return result;
        
        Rollback(result);
        return {-1};
    }
    
    void Rollback(vector<int> &result) {
        for (int i = 0; i < 5; ++i) {
            counts[i] += result[i];
        }
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */