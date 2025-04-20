class Solution {
public:
    int frq[1000];
    int numRabbits(vector<int>& answers) {
        int cnt=0;
        for(int x: answers)
            cnt+=(frq[x]++%(x+1)==0)*(x+1);
        return cnt;
    }
};