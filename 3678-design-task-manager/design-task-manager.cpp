class TaskManager {
public:
    set<pair<int,int>>st;
    unordered_map<int,int>mp;
    unordered_map<int,int>users;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto it : tasks){
            mp[it[1]] = it[2];
            st.insert({-it[2],-it[1]});
            users[it[1]] = it[0];
        }
    }
    
    void add(int usersId, int taskId, int priority) {
        mp[taskId] = priority;
        st.insert({-priority,-taskId});
        users[taskId] = usersId;
        
    }   
    
    void edit(int taskId, int newPriority) {
        st.erase({-mp[taskId],-taskId});
        mp[taskId] = newPriority;
        st.insert({-newPriority,-taskId});


    }
    
    void rmv(int taskId) {
        st.erase({-mp[taskId],-taskId});
        mp.erase(taskId);
        users.erase(taskId);

        
    }
    
    int execTop() {

         int uid = -1 ;
         if(st.size()){
            uid =  users[-(*st.begin()).second];
            st.erase(st.begin());
         }
         return uid;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */