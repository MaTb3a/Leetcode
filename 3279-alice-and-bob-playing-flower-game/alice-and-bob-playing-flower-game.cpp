class Solution {
public:
    long long flowerGame(int n, int m) {
      
      
       return 1LL*(n/2)*(m&1 ? m/2+1 : m/2)+1LL*(n&1 ? n/2+1:n/2)*(m/2);
    }
};