class Solution {
public:
    vector<vector<int>>dir = {
        {1,3}, // 1
        {0,2,4}, // 2
        {1,5}, // 3
        {0,4}, // 4
        {1,3,5},// 0
        {2,4}// 5
    };
    unordered_map<string,int>vis;

    int BFS(int p0,string s){
        queue< pair<int,string>>q;
        q.push({p0,s});
        vis[s] = 0;
        while(q.size()){
            int zeroPos = q.front().first;
            string s = q.front().second; // 412503 | 0 

            q.pop();
            if(s == "123450")return vis["123450"];
            for(int nInd :dir[zeroPos]){
                string curState = s;
                swap(curState[zeroPos],curState[nInd]);
                if(!vis.count(curState) ){
                    vis[curState] = vis[s]+1;
                    q.push({nInd,curState});
                }
            }

        }
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        string s ;
        for(auto row : board)
            for(auto c : row)
                s+='0'+c;

        return BFS(s.find('0'),s);

    }
};