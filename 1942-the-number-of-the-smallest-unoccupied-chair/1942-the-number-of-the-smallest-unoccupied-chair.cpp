class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> Friend = times[targetFriend];

        sort(times.begin(),times.end());

        set<int>chairs;
        for(int i = 0 ; i < n ;i++)chairs.insert(i);

        set<pair<int,int>>resereved;// timeleaving , idxChair

        for(int i = 0 ; i < n ;i++){
        
            while(resereved.size() && resereved.begin()->first <= times[i][0]){
                int chairIdx = resereved.begin()->second;
                chairs.insert(chairIdx);
                resereved.erase(resereved.begin());
            }

           int chairIdx = *chairs.begin();
           resereved.insert({times[i][1],chairIdx}); // log(n)
           chairs.erase(chairIdx);
           if(Friend == times[i])return chairIdx;
        }
        return -111;

    }
};