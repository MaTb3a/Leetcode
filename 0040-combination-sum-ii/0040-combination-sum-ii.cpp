class Solution {
public:
    vector<vector<int>>ans;
    vector<int>tmp;
    int n;
    void solve(int idx,int target,vector<int>& candidates){
        if(!target)
            ans.push_back(tmp);
        
        if(target <= 0 || idx == n)return;
        //take
        tmp.push_back(candidates[idx]);
        solve(idx+1,target - candidates[idx] ,candidates);
        tmp.pop_back();
        // leave
        while(idx+1 <n && candidates[idx] == candidates[idx+1])idx++;
        solve(idx+1,target,candidates);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates);
        return ans;
    }
};