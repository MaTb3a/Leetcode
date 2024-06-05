class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        dec = {}
        for word in words:
            d = {}
            for w in word:
                if w in d:
                    d[w] +=1
                else :
                    d[w] = 1
            if dec == {}:
                dec = d
            else :
                for i in range(0,26):
                    c = chr(i+97)
                    if c in dec and c in d:
                        dec[c] = min(dec[c],d[c])
                    else:
                        dec[c]=0
                   
        ans = []
        for ch in dec:
            cnt = dec[ch]
            while(cnt > 0):
                cnt-=1
                ans.append(ch)
        return ans
                    
                    