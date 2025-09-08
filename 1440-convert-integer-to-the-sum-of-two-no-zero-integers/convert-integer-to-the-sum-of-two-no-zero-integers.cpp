class Solution {
public:
    bool valid(int x){
        while(x){
            if(x%10 ==0)return 0;
            x/=10;
        }
        return 1;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1 ; i < n ;i++){
            if(valid(i) && valid(n-i))
                return {i,n-i};
        }
        return {-1,-1};
    }
};