class MyCalendar {
public:
  
    
    vector<pair<int,int>>v;
    bool book(int start, int end) {
         for(auto t : v){
             if(!(start>t.second || end-1 < t.first))
                 return 0;
            
         }
         v.push_back({start,end-1});
         return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */