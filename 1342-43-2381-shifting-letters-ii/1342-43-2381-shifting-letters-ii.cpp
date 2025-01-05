class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>v(n+1);
        for(auto it : shifts){
            int l = it[0],r = it[1], d = it[2];
            v[l]+= (d ? 1 : -1);
            v[r+1] +=(d ? -1 : 1);
        }
        for(int i = 0 ; i < n;i++){
            if(i)v[i]+=v[i-1];
            s[i] = (v[i]+s[i]-'a')%26+'a';
            if(s[i]<'a')s[i]+=26;
        }
        return s;

    }
};