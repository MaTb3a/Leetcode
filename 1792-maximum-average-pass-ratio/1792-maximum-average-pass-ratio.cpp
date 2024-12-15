class Solution {
public:
    struct ratio{
        int x,y;
        double r=(1.0*(x+1) / (y+1) ) - (1.0*x / y);
        bool operator<(const ratio &other)const{
            return other.r > r;
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<ratio> pr;
        for(auto it : classes)pr.push({it[0],it[1]});
       
       while(extraStudents--){
        auto t = pr.top();
        t.x++;t.y++; pr.pop();
        pr.push({t.x,t.y});
       }
       double ans = 0;
       while(pr.size()){
        int x = pr.top().x;
        int y = pr.top().y;
        pr.pop();
        ans+=(1.0*x/y);
       }
       return ans / classes.size();
    }
};