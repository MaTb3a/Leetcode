class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        long long mxh = horizontalCuts[0];
        long long mxv = verticalCuts[0];
        
        for(int i=1;i<horizontalCuts.size();i++)
            mxh=max(mxh,1LL*horizontalCuts[i]-horizontalCuts[i-1]);
        for(int i=1;i<verticalCuts.size();i++)
            mxv=max(mxv,1LL*verticalCuts[i]-verticalCuts[i-1]);
            return 1LL*(mxh*mxv)%(1000000007);
    }
};