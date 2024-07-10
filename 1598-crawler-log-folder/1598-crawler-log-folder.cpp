class Solution {
public:
    int minOperations(vector<string>& logs) {
        int dir = 0;
        for(auto log : logs){
            if(log == "../"){
                if(dir)dir--;
            }
            else if(log != "./")
                dir++;
        }
        return dir;
    }
};