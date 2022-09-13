class Solution {
public:
    bool validUtf8(vector<int>& data) {
        vector<string> v;
        for(int i=0;i<data.size();i++) {
            string s = bitset<8> (data[i]).to_string();
            v.push_back(s);
        }
        
        int cnt = 0;
        for(auto s: v) {
            if(cnt==0) {
                if( s[0]=='1' && s[1]=='1' && s[2]=='0') cnt =1;
                else if(s[0]=='1' && s[1]=='1' && s[2]=='1' && s[3]=='0') cnt=2; 
                else if(s[0]=='1' && s[1]=='1' && s[2]=='1' && s[3]=='1' && s[4]=='0') cnt=3;
                else if( s[0]!='0') return false;
            } 
            else {
                if(s[0]=='1' && s[1]=='0') cnt--;
                else return false;
            }
        }
        return cnt==0;
    }
};