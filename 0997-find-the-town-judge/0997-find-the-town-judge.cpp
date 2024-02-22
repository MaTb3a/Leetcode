class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>v(n+1);
        for(auto t : trust){
            v[t[1]]++;
            v[t[0]]--;
        }
        for(int i =1 ;i<=n;i++)
            if(v[i]==n-1)return i;
        return -1;
       
    }
};