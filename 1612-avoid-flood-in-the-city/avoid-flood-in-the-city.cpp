class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        map<int,int>mp;
        set<int>zeros;
        int n = rains.size();
        vector<int>ans(n,1);
        for(int i = 0 ; i < n;i++){
            if(!rains[i]){
                zeros.insert(i);
                continue;
            }
            if(mp.find(rains[i]) != mp.end()){
                auto it = zeros.lower_bound(mp[rains[i]]);
                if(it == zeros.end())
                    return {};
                ans[*it] = rains[i];
                zeros.erase(it);
                
            }
            mp[rains[i]] = i;
            ans[i]= -1;
        }
        return ans;

    }
};