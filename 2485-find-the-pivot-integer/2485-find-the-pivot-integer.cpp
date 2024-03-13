class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int st = 1 ,ed = n,cur = -1,md;
        while(st<=ed){
            md = (st+ed)/2;
            int tmp = (md*(md+1)/2);
            
            
            if(sum - tmp + md == tmp){
                cur = md;
                break;
            }
            else if (sum - tmp + md < tmp){
                ed = md -1;
            }
            else st =md+1;
        }
        return cur;
    }
};