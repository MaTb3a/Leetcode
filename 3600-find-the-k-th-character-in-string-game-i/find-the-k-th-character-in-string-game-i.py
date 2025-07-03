class Solution:
    def kthCharacter(self, k: int) -> str:

        def solve(s):
            res = s
            for x in s:
                c = ord(x) - ord('a')
                c+=1
                c%=26
                ch = chr(c+97)
                res+=ch
            return res
       
        word = str("a")
        while len(word) < k:
           word = solve(word)
        return word[k-1]
