class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        vector<int>frq(1001);
        for(int j  = 0 ; j < arr.size() ; j++){
            for(int k = j +1 ; k < arr.size(); k++){
                if(abs(arr[j] - arr[k]) > b)continue;
                int l = max(arr[j]-a,arr[k]-c); // mn i
                int r = min(arr[j]+a,arr[k]+c); // mx i
                if(l <=r)
                    cnt+= frq[min(1000,r)] - ( l > 0 ? frq[l-1] : 0);
            }
            for(int i = arr[j];i <= 1000;i++)frq[i]++;
        }
        return cnt;
    }
};