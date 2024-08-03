class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int>frq(1001);
        for(int x : arr)frq[x]++;
        for(int x : target){
            if(!frq[x])return false;
            frq[x]--;
        }
        return true;

    }
};