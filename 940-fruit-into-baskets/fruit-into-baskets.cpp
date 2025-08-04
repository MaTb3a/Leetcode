class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mp;
        int r = 0,mx = 0;
        for(int l = 0 ; l < fruits.size();l++){
            while(r < fruits.size() && (mp.size() < 2 || mp.find(fruits[r]) != mp.end())){
                mp[fruits[r]]++;
                mx=max(mx,r-l+1);
                r++;
            }
            mp[fruits[l]]--;
            if(!mp[fruits[l]])mp.erase(fruits[l]);
        }

        return mx;
    }
};