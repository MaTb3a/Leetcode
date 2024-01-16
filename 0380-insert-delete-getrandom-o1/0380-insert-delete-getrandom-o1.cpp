class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>v;
    RandomizedSet() {
        mp.clear();
        v.clear();
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())return false;
        v.push_back(val);
        mp[val]=v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())return false;
        mp[v.back()] =  mp[val];
        swap(v[v.size()-1],v[ mp[val]]);
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % v.size();
        return v[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */