class ATM {
public:
    vector<int>denomination;
    vector<int>bank;
    ATM() {
        denomination = {20,50,100,200,500};
        bank = {0,0,0,0,0};
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0 ; i < 5;i++)
            bank[i]+=banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        vector<int>current(5);
        for(int i = 4 ; i >= 0 ;i--){
            current[i] = min(bank[i], amount/denomination[i]);
            amount -= current[i]*denomination[i];
        }
        if(amount)return {-1};
        for(int i = 4 ; i >= 0 ;i--)
            bank[i]-=current[i];
        return current;

        
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */