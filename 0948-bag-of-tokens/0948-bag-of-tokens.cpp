class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(),tokens.end());
        int st = 0, ed = tokens.size()-1,score = 0 , mx = 0;
        while(st<=ed){
            if(power>= tokens[st]){
                power-=tokens[st++];
                score++;
                mx=max(mx,score);
            }
            else {
                if(!score)break;
                score--;
                power+=tokens[ed--];
            }
        }
        return mx;
    }
};