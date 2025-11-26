class Solution {
public:
    bool check_digits(string s){
        int idx = s.find(' ');
        while(idx != s.size()){
            if(isalpha(s[idx]))return false;
            idx+=1;
        }
        return true;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
  
        
        // dig -> sort them as it is based on i (0,n)
        // let -> s.substr(4) , id , str
        vector<string>digits;
        vector<pair<string,pair<string,string>>>ll;
        
        for(string s : logs){
            if(check_digits(s))
                digits.push_back(s);
            else{
                ll.push_back({s.substr(s.find(' ')),{s.substr(0,s.find(' ')),s}});
            }
        }
        
        sort(ll.begin(),ll.end());
        vector<string>ans;
        for(auto it : ll)
            ans.push_back(it.second.second);
        ans.insert(ans.end(),digits.begin(),digits.end());
        return ans;
    }
};