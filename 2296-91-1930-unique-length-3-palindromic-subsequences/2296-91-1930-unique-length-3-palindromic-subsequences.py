class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        left = [-1] * 26
        right = [0] * 26
        
        for i, ch in enumerate(s):
            idx = ord(ch) - ord('a')
            if left[idx] == -1:
                left[idx] = i
            else:
                right[idx] = i
        
        ans = 0
        for i in range(26):
            if right[i] == 0:
                continue
            visited = set()
            for j in range(left[i] + 1, right[i]):
                if s[j] not in visited:
                    visited.add(s[j])
            ans += len(visited)
        
        return ans
