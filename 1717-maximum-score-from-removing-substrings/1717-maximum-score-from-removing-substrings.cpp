class Solution {
public:
  
    int solve(string &s,string remove,int val){
        string newS = "";
        int score = 0;
        for(int i = 0 ; i < s.size();i++){
            if(!newS.empty() && newS.back() ==  remove[0] && s[i] == remove[1]){
                score+=val;
                newS.pop_back();
            }
            else newS.push_back(s[i]);
        }
        s = newS;
        return score;
    }
    int maximumGain(string s, int x, int y) {
         
       if(x > y)
            return solve(s,"ab",x) + solve(s,"ba",y);

        return  solve(s,"ba",y) + solve(s,"ab",x);

    }
};