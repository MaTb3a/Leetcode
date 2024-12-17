class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>frq(26);
        for(char c : s)frq[c-'a']++;
        vector<int>v;
        for(int i = 0 ; i < 26 ;i++)
            if(frq[i])v.push_back('a'+i);

        s= "";

        while(v.size()){ // a b c ,,,,, z 
            int lst = v.back() - 'a'; // 26
            v.pop_back();
            int mn = min(repeatLimit,frq[lst]); // 2
            frq[lst]-=mn;
            s+=string(mn,lst+'a'); ///zzccc

            if(v.size() && frq[lst]){
                int cur = v.back() - 'a';
                s.push_back('a'+cur);
                frq[cur]--;
                if(frq[cur]==0)v.pop_back();
                v.push_back(lst+'a');
            }

        }
        return s;

    }
};