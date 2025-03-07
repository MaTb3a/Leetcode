class Solution {
public:
  
    bitset<1000001>vis; 
    void sieve(int n){
        vis[0] = vis[1] = 1;
        for(int i  = 2 ; i*i <= n; i++){
            if(!vis[i])
                for(int j = i+i; j <= n ;j+=i)
                    vis[j] = 1;
        }
    }
    vector<int> closestPrimes(int left, int right) {
        sieve(right);
        int a= -1,b= -1,lst = -1,g = 1e9;
        for(int i = left ; i <= right;i++){ 
            if(vis[i])continue;
            if(lst != -1 && i - lst  < g){
                g = i - lst;
                a = lst,b= i;
            }
            lst = i;
        }
        return {a,b};
    }
};