struct Segment{
    vector<int>seg;
    Segment(){

    }
    Segment(int n){
        seg = vector<int>(4*n);
    }
    void build(int n,int s,int e,vector<int>&v){
        if(s == e){
            seg[n] = v[s];
            return;
        }
        int md = (s+e)/2;
        build(n*2+1,s,md,v);
        build(n*2+2,md+1,e,v);
        seg[n] = seg[n*2+1] + seg[n*2+2];
    }
    int get(int n,int s,int e,int l,int r){
        if(s > r || e < l)return 0;
        if(s >= l && e <= r)return seg[n];
        int md = (s+e)/2;
        return get(n*2+1,s,md,l,r) + get(n*2+2,md+1,e,l,r);
    }
    void update(int n,int s,int e,int at,int val){
        if(at > e || at < s)return ;
        if(s == e){
            seg[n] = val; 
            return;
        }
        int md = (s+e)/2;
        update(n*2+1,s,md,at,val);
        update(n*2+2,md+1,e,at,val);
        seg[n] = seg[n*2+1] + seg[n*2+2];
    }

};

class NumArray {
public:
    Segment seg;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg = Segment(n);
        seg.build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        seg.update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return seg.get(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */