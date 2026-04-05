class Solution:
    def judgeCircle(self, moves: str) -> bool:
        x,y = 0,0
        for i in moves:
            if i == 'R': y+=1
            elif i == 'L': y-=1
            elif i == 'U': x+=1
            else: x-=1
        return x == 0 and y == 0