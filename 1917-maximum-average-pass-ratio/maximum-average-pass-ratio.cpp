class Solution {
public:
    double calc(int x,int y){
        return 1.0*(x+1) / (y+1) - (double)x / y;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pr;
        //cout<<fixed<<setprecision(9);
        for(auto it : classes)pr.push({calc(it[0],it[1]),{it[0],it[1]}});

        while(extraStudents--){
            auto t = pr.top();pr.pop();
            t.second.first++;
            t.second.second++;
            
            t.first = calc(t.second.first,t.second.second);
            pr.push(t);
        }
        double ans = 0;
        while(pr.size()){
            ans+=pr.top().second.first*1.0/pr.top().second.second;
            pr.pop();
        }
        double ave = ans / (int)classes.size();
        return ave;
    }
};