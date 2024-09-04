class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int mx= 0, x= 0 ,y= 0,dir = 0;
        map<pair<int,int>,bool>mp;
        for(auto it : obstacles)mp[{it[0],it[1]}]= true;

        for(int it : commands){ 
            if(it == -2)dir--;
            else if(it == -1)dir++;
            else {
                dir = ((dir%4)+4)%4;
                int nx = x, ny = y;
                for(int i = 1 ; i <=  it; i++){  
                    if(!dir)ny++;
                    else if(dir == 1)nx++;
                    else if(dir == 2)ny--;
                    else nx--;
                    if(mp.find({nx,ny}) != mp.end())break;
                    x = nx; y= ny;
                    mx=max(mx,x*x+y*y);
                }
            }
        }
        return mx;
    }
};