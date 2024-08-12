class KthLargest {
    priority_queue<int, vector<int> , greater<int> >pr;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for(auto it : nums)pr.push(it);
        while(pr.size() > k)pr.pop();
    }
    
    int add(int val) {
        pr.push(val);
        if(pr.size() > k)
           pr.pop();
        return pr.top();
    }   
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */