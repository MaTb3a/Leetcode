class Solution {
public:
    vector<int>v;
    bitset<21>vis;
    bool solve(int idx,int n){
        if(idx == 2*n-1)return true;
        if(v[idx]) return solve(idx+1,n);
        for(int i = n ; i >= 1;i--){ // n 
            if(vis[i])continue;
            int nxt = i == 1 ? idx : idx + i;
            if(nxt >= v.size()|| v[nxt] ) continue;

            v[idx] = v[nxt] = i; vis[i] = 1;
            if(solve(idx+1,n))return true;
            v[idx] = v[nxt] = 0; vis[i] = 0;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
       v = vector<int>(2*n-1);
       solve(0,n);
       return v;
    }
};