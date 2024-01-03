class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, cur = 0 ,lst = 0;
        for(auto t : bank){
            int cur = count(t.begin(),t.end(),'1');
            ans+=cur*lst;
            if(cur)lst = cur;
        }
     
        return ans;
    }
};