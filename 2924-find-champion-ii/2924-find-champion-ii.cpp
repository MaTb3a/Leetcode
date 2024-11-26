class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        bitset<100>v;
        for(auto it : edges)v[it[1]] = 1;
        int champion = -1;
        for(int i = 0 ; i < n ;i++){
            if(!v[i]){
                if(champion == -1)
                    champion = i; // 0
                else 
                    return -1;
            }
        }
        return champion;
        
    }
};