
    class Solution { 
public: 
    int dp[102][102]; 
    int x,y,z; 
    bool solve (string& s1, string& s2, string &s3, int a, int b, int c) 
    { 
        if(a==x && b==y && c==z)  
            return true; 
        int &ret=dp[a][b];
        
        if(ret !=-1) 
            return ret; 
       ret=0; 
       if(a<x && s1[a]==s3[c]) 
            ret |= solve(s1, s2, s3, a+1, b, c+1); 
           
       if(b<y &&s2[b]==s3[c]) 
            ret |= solve(s1, s2, s3, a, b+1, c+1); 
         
          
        return ret; 
    } 
    bool isInterleave(string s1, string s2, string s3) { 
        if (s1.size()+s2.size()!= s3.size()) 
            return false ; 
        x=s1.size(); 
        y=s2.size(); 
        z=s3.size(); 
        memset(dp, -1, sizeof(dp)); 
        return solve(s1, s2, s3,0,0,0); 
         
    } 
};