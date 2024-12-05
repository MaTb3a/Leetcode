class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();       
        for(int i = 0,j=0; i < n || j < n ;i++,j++){
            while(start[i]=='_')i++;
            while(target[j]=='_')j++;
             if(start[i] != target[j])return false;
             if(start[i] == 'L' && i < j)return false;
             if(start[i] == 'R' && i > j)return false;
        }
        return true;

    }
};