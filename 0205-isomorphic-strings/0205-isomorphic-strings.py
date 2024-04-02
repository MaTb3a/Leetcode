class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dic = {}
        vis = {}
        s=list(s)
        t=list(t)
        for i in range(0,len(s)):
            if (s[i] not in dic) :
                if(t[i] in vis) :
                    return False
                dic[s[i]] = t[i]
                vis[t[i]] = 1
            s[i] = dic[s[i]]

              
        
        
        return s == t;