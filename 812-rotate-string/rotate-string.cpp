class Solution {
public:
    bool check(int i,int j,string &s,string &d){
        int cnt = 0,n = s.size();
        while(cnt < s.size()){
            if(s[i]!=d[j])return false;
            i++;j++;
            i%=n;j%=n;
            cnt++;
        }
        return cnt == n;
    }
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())return false;
        vector<int>a,b;
        for(int i = 0 ; i < s.size();i++)
            if(s[i] == s[0])a.push_back(i);
        for(int j = 0 ; j < goal.size();j++)
            if(goal[j] == s[0])b.push_back(j);
   //     cout<<a.size()<<" "<<b.size()<<"\n";
        for(int i = 0 ; i < a.size();i++)
            for(int j = 0;j<b.size();j++)
                if(check(a[i],b[j],s,goal))return true;
        return false;
    }
};