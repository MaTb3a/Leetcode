class Solution {
public:
    long long flowerGame(int n, int m) {
      
       long long oddN = n&1 ? n/2+1 : n/2, EvenN = n/2;
       long long oddM = m&1 ? m/2+1 : m/2, EvenM = m/2;
      
       return oddN*EvenM+EvenN*oddM;
    }
};