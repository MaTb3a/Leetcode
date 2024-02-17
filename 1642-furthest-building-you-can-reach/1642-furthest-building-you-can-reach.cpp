class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pr;
        long long sum =0;
        int n = heights.size();
        heights.push_back(0);
        for(int i = 0 ; i < n ;i++){
            if(heights[i] < heights[i+1]){
                if(sum+heights[i+1]-heights[i] <= bricks){
                    sum+=heights[i+1]-heights[i];
                    pr.push(heights[i+1]-heights[i]);
                }
                else if(ladders){
                    pr.push(heights[i+1]-heights[i]);
                    sum+=heights[i+1]-heights[i];
                    ladders--;
                    sum-=pr.top();pr.pop();
                }
                else return i;
            }
        }
        return n-1;
    }
};