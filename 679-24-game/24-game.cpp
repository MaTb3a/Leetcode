class Solution {
vector<double> compute(double a, double b){
    return {a+b, a-b, b-a, a*b, a/b, b/a};
}

bool solve(vector<double>&v){
    if(v.size()==1) return abs(v[0]-24) < 0.0001;

    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            double x = v[i];
            double y = v[j];
            vector<double> next;
            for(double &num: compute(x,y)){
                next.clear();
                next.push_back(num);
                for(int k=0; k<v.size(); k++){
                    if(k!=i and k!=j) next.push_back(v[k]);  
                }
                if(solve(next)) return true;  
            }
        }
    }
    return false;
}

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> v(cards.begin(), cards.end());
        return solve(v);
    }
};