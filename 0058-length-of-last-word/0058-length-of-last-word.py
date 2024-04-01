class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = list(s)
        while(len(s) and s[-1] == ' ') :
            s.pop()
        cnt = 0
        while(len(s) and s[-1]!= ' ') :
            s.pop();
            cnt+=1
        return cnt;