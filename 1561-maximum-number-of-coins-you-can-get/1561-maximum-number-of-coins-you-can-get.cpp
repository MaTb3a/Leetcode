class Solution {
public:
    int maxCoins(vector<int>& piles) {
        deque<int>q(piles.begin(),piles.end());
        sort(q.begin(),q.end());
        int ans= 0;
        while(q.size()){
            q.pop_front();
            q.pop_back();
            ans+=q.back();
            q.pop_back();
        }
        return ans;

    }
};