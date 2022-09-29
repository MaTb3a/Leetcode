class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        multiset<int>mst;
        for(auto t : arr)
            mst.insert(t);
        vector<int>ans;
        while(k--){
            auto it = mst.lower_bound(x);
            if(it!=mst.begin()&&it!=mst.end()){
                auto it2 = it;
                --it2;
                if(abs(*it2-x)<=abs(*it-x)){
                    ans.push_back(*it2);
                    mst.erase(it2);
                }
                else {
                     ans.push_back(*it);
                    mst.erase(it);
                }
            }
            else if(it==mst.end()){
                --it;
                 ans.push_back(*it);
                    mst.erase(it);
            }
             else {
                    ans.push_back(*it);
                    mst.erase(it);
                }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};