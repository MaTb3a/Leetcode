class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int l=0,r=tokens.size()-1,cnt=0;
        while(l<r){
            while(power>=tokens[l])cnt++,power-=tokens[l++];
            if(cnt && power+tokens[r]>=tokens[l] && l!=r)cnt--,power+=tokens[r--];
            else break;
        }
        if(l==r && power>=tokens[l])cnt++;
        return cnt;
            
    }
};