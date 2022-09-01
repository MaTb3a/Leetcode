class Solution {
public:
    map<map<int,int>,bool>mp;
    void solve(int x){
        map<int,int>cur;
        while(x){
            cur[x%10]++;
            x/=10;
        }
        mp[cur]=1;
    }
    bool reorderedPowerOf2(int n) {
        
        for(int i=0;i<31;i++)
           solve(1<<i);
        
        map<int,int>m;
        while(n){
            m[n%10]++;
                n/=10;
        }
        return mp[m];
    }
};