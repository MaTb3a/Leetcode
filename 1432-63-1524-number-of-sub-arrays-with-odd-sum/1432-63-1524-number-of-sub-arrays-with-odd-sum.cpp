class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ev = 1 ,odd = 0,sum = 0;
        for(int x : arr){
            sum+=x;
            (sum&1) ? odd++ : ev++;
        }
        return (1LL*odd*ev)%1000000007;
    }
};