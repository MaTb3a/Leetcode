class Solution:
    def partitionLabels(self, s: str) -> list[int]:
        lst = [0] * 26
        
        for i in range(len(s)):
            lst[ord(s[i]) - ord('a')] = i
        
        result = []
        start = 0
        end = 0
        
        for i in range(len(s)):
            end = max(end, lst[ord(s[i]) - ord('a')])
            
            if end == i:
                result.append(end - start + 1)
                start = end + 1
        
        return result