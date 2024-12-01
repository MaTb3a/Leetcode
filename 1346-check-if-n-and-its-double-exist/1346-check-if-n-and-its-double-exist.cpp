class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end()); // n*log(n)
        for(int i = 0 ; i < arr.size();i++){
            if(binary_search(arr.begin(),arr.begin()+i,arr[i]*2))return true;
            if(binary_search(arr.begin()+i+1,arr.end(),arr[i]*2))return true;
        }
        return false;
    }
     // 3,1,7,11
     // 1 3 7 11


};