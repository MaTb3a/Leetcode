class Solution:
    def reverseWords(self, s: str) -> str:
        lst = []
        w = ''
        for c in s:
            if c == ' ':
                if w:
                    lst.append(w)
                    w = ''
            else:
                w+=c
        if w:
            lst.append(w)
        
        ans = ''
        for x in lst[::-1]:
            ans+=x+' '
        return ans[:-1]
