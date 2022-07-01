class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        long long ans=0;
        for(auto t : boxTypes){
            if(truckSize>=t[0]){
                ans+=t[0]*t[1];
                truckSize-=t[0];
            }
            else {
                ans+=truckSize*t[1];
                break;
            }
        }
        return ans;
    }
};