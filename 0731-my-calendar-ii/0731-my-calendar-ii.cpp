class MyCalendarTwo {
public:
    map<int,int>mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int s2, int e2) {
        mp[s2]++;
        mp[e2]--;
        int cnt = 0;
        for(auto it : mp){
            cnt+=it.second;
            if(cnt == 3){
                mp[s2]--;
                mp[e2]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */