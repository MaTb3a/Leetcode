class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)return "1";
        string ret = countAndSay(n-1);// 2
        string ans = "";int cnt = 1;
        for(int i = 0 ; i < ret.size();i++){
            if(ret[i] == ret[i+1])cnt++;
            else {
                ans.push_back(cnt+'0'); // 1
                ans.push_back(ret[i]); // 1
                cnt = 1;
            }
        }
        return ans;
    }
};