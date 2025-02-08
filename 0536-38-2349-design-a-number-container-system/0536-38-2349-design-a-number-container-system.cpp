class NumberContainers {
public:
    unordered_map<int,int>mp;
    unordered_map<int,set<int>>idxs;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp.count(index))
            idxs[mp[index]].erase(index);
        mp[index] = number;
        idxs[number].insert(index);
    }
    
    int find(int number) {
        return idxs[number].size() ? *idxs[number].begin() : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
 auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();