class LRUCache {
public:
    deque<int>dq; // flag -1 means deleted;
    unordered_map<int,int>cache,mp;
    int sz,start = 0;
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)== cache.end())return -1;
        dq[mp[key]] = -1;
        mp[key] = dq.size();
        dq.push_back(key);
        return cache[key];
    }
    
    void put(int key, int value) {
    
        while(start < dq.size() && dq[start] == -1)start++;

        if(cache.find(key)!= cache.end()){
            dq[mp[key]] = -1;
            cache[key] = value;
            mp[key] = dq.size();
            dq.push_back(key);
            return;
        }
        if(cache.size() == sz){
            cache.erase(dq[start]);
            mp.erase(dq[start]);
            start++;
        }
       
       mp[key] = dq.size();
       dq.push_back(key);
       cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */