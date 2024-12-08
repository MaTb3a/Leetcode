class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int,int>>pr; // f ,s  => (end , valu)
        sort(events.begin(),events.end());
        int mx = 0, mxV = 0;
        for(int i = 0 ; i < events.size();i++){
            //               old event (end). | cur  (st)
            while(pr.size() && -pr.top().first < events[i][0]){
                mxV=max(mxV,pr.top().second);
                pr.pop();
            }
            mx=max(mx,events[i][2]+mxV);
            pr.push({-events[i][1],events[i][2]});
        }
        return mx;
    }
};