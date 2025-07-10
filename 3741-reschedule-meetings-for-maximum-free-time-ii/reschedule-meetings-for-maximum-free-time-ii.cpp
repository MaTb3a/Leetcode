class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int>b,sp;
        int n = startTime.size();
        int lst = 0;
        for(int i = 0 ; i < n;i++){
            int block = endTime[i] - startTime[i];
            int space = startTime[i] - lst;
            lst = endTime[i];
            b.push_back(block);
            sp.push_back(space);
        }
        
        sp.push_back(eventTime - endTime.back());
        
        int m = sp.size();
        vector<int>L(m),R(m);
        for(int i = 1 ; i < m;i++){
            L[i] = max(L[i-1],sp[i-1]);
        }
        for(int i = m-2; i >= 0;i--){
            R[i] = max(R[i+1],sp[i+1]);
        }
         
        int ans = 0;
        for(int i = 0 ; i < b.size();i++){
            if(b[i] <= L[i] || b[i] <= R[i+1])ans=max(ans,b[i]+sp[i]+sp[i+1]);
            else ans = max(ans,sp[i]+sp[i+1]);
        }
        return ans;
    }
};