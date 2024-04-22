from typing import List

class Solution:

    
    def bfs(self,deadends,target):
        q = []
        q.append(("0000",0))
        vis = set()
        while len(q):
            number = q[0][0]
            dist = q[0][1]
            q.pop(0)
            if number == target:
                return dist
            if number in vis or number in deadends:
                continue
            vis.add(number)
            for i in range(0,4):
                digit_plus = (int(number[i]) + 1) % 10
                digit_minus = (int(number[i]) - 1) % 10
                plus = number[:i]+str(digit_plus)+number[i+1:]
                minus = number[:i]+str(digit_minus)+number[i+1:]
                q.append((plus,dist+1))
                q.append((minus,dist+1))
        return -1
                    
            
            

    def openLock(self, deadends: List[str], target: str) -> int:
        return self.bfs(deadends,target)
        
        
    
