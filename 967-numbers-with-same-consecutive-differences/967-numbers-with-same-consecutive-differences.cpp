class Solution {
public:
    
    vector<int>ans;
    void solve(int i,int lst,int num,int n,int k){
        if(i==n){
            ans.push_back(num);
            return;
        }
       
        for(int j=0;j<10;j++){
            if(abs(lst-j)==k)
                solve(i+1,j,num*10+j,n,k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        ans.clear();
        for(int i=1;i<10;i++)
            solve(1,i,i,n,k);
        return ans;
    }
};