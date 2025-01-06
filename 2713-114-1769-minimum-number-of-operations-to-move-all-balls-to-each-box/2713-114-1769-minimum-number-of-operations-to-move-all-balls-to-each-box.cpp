class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(),op = 0 , L = 0 , R =0;
        for(int i = 0 ; i < n ;i++)
            if(boxes[i]=='1')op+=i,R++;
        vector<int>v(n);
        for(int i = 0 ; i < n ;i++){
            v[i] = op;
            if(boxes[i]=='1')L++,R--;
            op+=-R+L;
        }
        return v;
    }
};