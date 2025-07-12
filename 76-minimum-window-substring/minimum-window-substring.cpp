class Solution {
public:
    unordered_map<char,int>mp1,mp2;
    bool ok(){
        for(auto it : mp1)
            if(it.second > mp2[it.first])return false;
        return true;
    }
    string minWindow(string s, string t) {
        
        for(char ch : t)mp1[ch]++;
        int j = 0,len = 1e9;
        int x = 0,y = 0;
        for(int i = 0 ; i< s.size();i++){
             mp2[s[i]]++;
           
            while( j < s.size() && ok()){
                mp2[s[j]]--;
                if(i - j+1 < len){
                    x = i,y = j;
                    len=min(len,i-j+1);
                }
                j++;

            }
           
        }
        return len != 1e9  ?  s.substr(y,len) : "";
    }
};