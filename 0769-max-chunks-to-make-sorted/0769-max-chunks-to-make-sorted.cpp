class Solution {
public:
   
    int maxChunksToSorted(vector<int>& arr) {
        if(!arr[0])arr[0]=1;
        else {
            arr[1]=max(arr[0],arr[1]);
            arr[0]=0;
        }
        for(int i = 1 ; i < arr.size();i++){
            arr[i]=max(arr[i],arr[i-1]);
            if(arr[i] == i)arr[0]++;
        }
        return arr[0];
    }
};