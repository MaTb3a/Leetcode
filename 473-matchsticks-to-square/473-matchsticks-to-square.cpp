class Solution {
public:
    int mx;
   bool solve(vector<int>& matchsticks , int i , vector<int>& a){
         
        if(i==matchsticks.size()) return 1;
        for(int j=0;j<4;j++){ 
            if(a[j]+matchsticks[i]<=mx){
                a[j]+=matchsticks[i];
                if(solve(matchsticks,i+1,a)) return 1;
                a[j]=a[j]-matchsticks[i];
            }
            
        }
        return 0;
        
    } 
    
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(auto t : matchsticks)sum+=t;
        mx=sum/4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        vector<int>v(4);
        return sum%4==0 ? solve(matchsticks,0,v) : 0;
    }
};