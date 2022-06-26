class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0,mx=0,all=0;
        int sz=cardPoints.size()-k;
        for(int i=0;i<cardPoints.size();i++){
            all+=cardPoints[i];
            if(i<sz)
                sum+=cardPoints[i];
        }
        
        mx=max(mx,all-sum);
        for(int i=sz;i<cardPoints.size();i++){
            sum-=cardPoints[i-sz];
            sum+=cardPoints[i];
            mx=max(mx,all-sum);
        }
        return mx;
    }
};