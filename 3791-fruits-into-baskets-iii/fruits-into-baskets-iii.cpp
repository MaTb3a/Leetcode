class Solution {
public:
    vector<int>segTree;
    void buildSegTree(vector<int>&baskets,int i,int l,int r){
        if(l==r){
            segTree[i]=baskets[l];
            return;
        }

        int mid=l+(r-l)/2;

        buildSegTree(baskets,2*i+1,l,mid);
        buildSegTree(baskets,2*i+2,mid+1,r);

        segTree[i]=max(segTree[2*i+1],segTree[2*i+2]);
    }
    bool querySegTree(int i,int l,int r,int val){
        if(segTree[i]<val){
            return false;
        }

        if(l==r){
            segTree[i]=-1;
            return true;
        }

        int mid=l+(r-l)/2;
        bool placed=false;

        if(segTree[2*i+1]>=val){
            placed=querySegTree(2*i+1,l,mid,val);
        } else{
            placed=querySegTree(2*i+2,mid+1,r,val);
        }
        
        segTree[i]=max(segTree[2*i+1],segTree[2*i+2]);
        return placed;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();

        segTree.resize(4*n,-1);
        buildSegTree(baskets,0,0,n-1);

        int ans=0;
        for(int &i:fruits){
            if(querySegTree(0,0,n-1,i)==false){
                ans++;
            }
        }
        return ans;
    }
};