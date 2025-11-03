class Solution 
{
public:
    int minCost(string s, vector<int>& t) 
    {
        int sh=s.size(), sum=0;
        for(int i=0; i<sh-1; i++)
            if(s[i]==s[i+1])
                sum+=min(t[i], t[i+1]), t[i+1]=max(t[i], t[i+1]);
        return sum;
    }
};