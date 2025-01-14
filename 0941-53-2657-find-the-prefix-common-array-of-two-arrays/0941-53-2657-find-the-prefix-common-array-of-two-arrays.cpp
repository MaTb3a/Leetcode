class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>v(A.size());
        bitset<51>vis,vis2;
       for(int i = 0 ; i < A.size();i++){
        vis[A[i]] = 1;
        vis2[B[i]] = 1;
        v[i] = (vis & vis2).count();
       }
       return v;
    }
};