class LRUCache {
public:
    set<pair<int,int>>st;
    map<int,int>cache;
    map<int,int>frq;
    int sz,time = 1;
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)== cache.end())return -1;
        auto it = st.find({frq[key],key});
        st.erase(it);
        frq[key] = time;
        st.insert({time++,key});
        return cache[key];
    }
    
    void put(int key, int value) {
        if(cache.find(key)!= cache.end()){
            cache[key] = value;
            st.erase({frq[key],key});
            frq[key] = time;
            st.insert({time++,key});
            return;
        }
        if(cache.size() == sz){
            cache.erase(st.begin()->second);
            frq.erase(st.begin()->second);
            st.erase(st.begin());
        }
        frq[key] = time;
        st.insert({time++,key});
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */