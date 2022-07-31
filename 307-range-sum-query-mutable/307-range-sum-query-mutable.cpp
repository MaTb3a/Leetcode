class NumArray {
public:
    int seg[100005];
    void build(vector<int>& nums,int n,int s,int e){
        if(s==e){
            seg[n]=nums[s-1];
            return ;
        }
        build(nums,2*n,s,(s+e)/2);
        build(nums,2*n+1,(s+e)/2+1,e);
        seg[n]=seg[2*n]+seg[2*n+1];
    }
  
    int get(int n,int s,int e,int l ,int r){
        if(s>r || e<l)return 0;
        if(s>=l && e<=r)return seg[n];
        return get(2*n,s,(s+e)/2,l,r)+get(2*n+1,(s+e)/2+1,e,l,r);
    }
    
    void updateSeg(int n,int s,int e,int at,int val){
        if(s>at || e < at)return ;
        if(s==e){
            seg[n]=val;
            return; 
        }
        updateSeg(2*n,s,(s+e)/2,at,val);
        updateSeg(2*n+1,(s+e)/2+1,e,at,val);
        seg[n]=seg[2*n]+seg[2*n+1];
        
    }
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        build(nums,1,1,n);
    }
    
    void update(int index, int val) {
        updateSeg(1,1,n,index+1,val);
    }
    
    int sumRange(int left, int right) {
        return get(1,1,n,left+1,right+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */