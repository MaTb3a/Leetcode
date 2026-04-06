class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        # -1 right
        # -2 left 

        # north -> left,right
        # left ->  south,north
        # south -> right,left
        # right -> south,north


        # dir north 0 1    right(-1)->  (right/east) 1,0     , left(-2) -> -1,0
        #     east  1 0          -1 ->    sount    0,-1       , north   0,1
        #     south 0 -1         -1->    west     -1,0       , east  1,0
        #     west  -1 0         -1 ->    north    0,1       ,  south 0,-1 
        mp = {}
        mp[0,1,0] = [0,1]
        mp[0,1,-1] = [1,0]
        mp[0,1,-2] = [-1,0]

        mp[1,0,0] = [1,0]
        mp[1,0,-1] = [0,-1]
        mp[1,0,-2] = [0,1]

        mp[0,-1,0] = [0,-1]
        mp[0,-1,-1] = [-1,0]
        mp[0,-1,-2] = [1,0]

        mp[-1,0,0] = [-1,0]
        mp[-1,0,-1] = [0,1]
        mp[-1,0,-2] = [0,-1]

        x,y,dx,dy=0,0,0,1
        ans = 0
        obs = set()
        for a,b in obstacles:
            obs.add((a,b))
        for c in commands:
            if c < 0:
                [dx,dy] = mp[dx,dy,c]
            else:
                best = 0
                for i in range(1,c+1):
                    if (x+dx*i,y+dy*i) in obs:
                        break
                    best = i
                x,y = x+dx*best,y+dy*best
                ans = max(ans,x*x+y*y)
        return ans

        