class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        rem = (k-len(s)%k)%k
        s+=str(fill)*rem
        ans = [ s[i:i+k] for i in range(0,len(s),k)]
        return ans