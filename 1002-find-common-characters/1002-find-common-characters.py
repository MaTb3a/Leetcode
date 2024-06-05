class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        curCount = Counter(words[0])
        for word in words[1:]:
            curCount&=Counter(word)
        ans = []
        for ch,num in curCount.items():
            ans.extend([ch]*num)
        return ans
                    
                    