class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>frq(k);
        for(auto it : arr)frq[(it%k+k)%k]++;

        if(frq[0]&1)return false;
        
        for(int i = 1 ; i < k;i++)
            if(frq[i] != frq[k-i])
                return false;
            
        return true;

    }
};