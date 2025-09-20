class Router {
public:
    int sz;
    queue<vector<int>>q;
    map<int,deque<int>>data;
    map<vector<int>,bool>mp;
    Router(int memoryLimit) {
        sz = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(mp.find({source,destination,timestamp}) != mp.end())
            return false;
        if(sz == mp.size()){
            forwardPacket();
        }
        mp[{source,destination,timestamp}] = true;
        q.push({source,destination,timestamp});
        data[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty())return {};
        mp.erase(q.front());
        data[q.front()[1]].pop_front();
        vector<int>v = q.front();
        q.pop();
        return v;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it1 = lower_bound(data[destination].begin(),data[destination].end(),(startTime));
        auto it2 = upper_bound(data[destination].begin(),data[destination].end(),(endTime));
        return it2 - it1;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */