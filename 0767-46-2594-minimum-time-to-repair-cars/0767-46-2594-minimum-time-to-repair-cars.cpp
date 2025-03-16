class Solution {
public:
    int frq[101];
    bool ok(long long t, int cars){
        long long cnt = 0;
        for(int i = 1 ; i <= 100 ; i++)
             cnt += (long long)sqrt(t/i) * frq[i];
        return cnt>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int mn = 1e9;
         for(int r : ranks)frq[r]++,mn=min(mn,r);
        long long st = 1, ed = 1LL*mn*cars*cars , cur = -1,md;  
        while(st<=ed){
            md = (st+ed)/2;
            if(ok(md,cars)){
                cur = md;
                ed = md -1;
            }
            else st = md+1;
        }
        return cur;
    }
};