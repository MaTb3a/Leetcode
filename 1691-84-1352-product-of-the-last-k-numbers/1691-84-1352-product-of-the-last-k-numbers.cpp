class ProductOfNumbers {
public:
    vector<int>v{1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(!num)v.resize(1);
        else v.push_back(num*v.back()); 
    }
    
    int getProduct(int k) {
        return v.size() <= k ? 0 : v.back() / v[v.size()-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */