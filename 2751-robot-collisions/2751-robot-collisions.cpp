class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int>idxs(n); 
        iota(idxs.begin(),idxs.end(),0); 
    
        sort(idxs.begin(),idxs.end(),[&](int a,int b){
            return positions[a] < positions[b];
        });
        stack<int>stk;

        for(auto i : idxs){ 
            if(directions[i] == 'R')
                stk.push(i);
            else { // L
                while(stk.size() && healths[i]){
                    int j = stk.top();
                    if(healths[j] > healths[i]){
                        healths[i] = 0;
                        healths[j]--;
                    }
                    else if(healths[j] < healths[i]){
                        healths[j] = 0;
                        healths[i]--;
                        stk.pop();
                    } 
                    else {
                         healths[i] = healths[j] = 0;
                          stk.pop();
                    }
                }
            }
        }
        vector<int>ans;
        for(int i = 0 ; i < n ;i++)
            if(healths[i])
                ans.push_back(healths[i]);

        return ans;


    }
};