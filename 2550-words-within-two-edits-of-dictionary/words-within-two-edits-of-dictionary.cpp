class Solution {
public:
    int can(string a, string b){
        int cnt= 0;
        for(int i = 0 ; i < a.size();i++){
            if(a[i] != b[i])cnt++;
        }
        return cnt;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>v;
        for(string s : queries){
            for(string d: dictionary){
                if(can(s,d) <= 2){
                    v.push_back(s);
                    break;
                }
            }
        }
        return v;
    }
};