class Solution {
public:
    struct node {
        int ps,num,idx,l,r;
    };
    int calcPrimeScore(int x){
        int cnt = 0;
        for(int i = 2 ; i * i<= x ;i++){
            if(x%i==0){
                cnt++;
                while(x%i==0)x/=i;
            } 
        }
        return cnt + (x>1);
    }
    const int mod = 1e9 + 7;
    inline long long fastPower(int base,int p){
        if(!p)return 1;
        long long same = fastPower(base,p/2)%mod;
        if(p&1) return (((same * same)%mod) * base)%mod;
        else return (same * same)%mod;
    }
    int maximumScore(vector<int>& nums, int k) {
        vector<node>v(nums.size());
        int n = nums.size();
        for(int i = 0 ; i < n ;i++)
            v[i] = node(calcPrimeScore(nums[i]),nums[i],i,-1,n);
            
        
        stack<int>stk;
        for(int i = 0 ; i < n ;i++){
            while(stk.size() && v[i].ps > v[stk.top()].ps){
                v[stk.top()].r =i;
                stk.pop();
            }
            if(stk.size())v[i].l = stk.top();
            stk.push(i);
        }
        sort(v.begin(),v.end(),[&](node a,node b){
            return a.num > b.num;
        });
        int ans = 1;
        for(auto x : v){
            int range = min(1LL*k,1LL*(x.idx - x.l) * (x.r - x.idx));
            k-=range;
            ans  = (ans * fastPower(x.num,range))%mod; 
        }
        return ans;

    }
};