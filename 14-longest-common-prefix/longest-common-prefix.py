class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = ""
        m = len(strs[0])
        for i in range(m):
            for j in range(1,len(strs)):
                c = strs[0][i]
                if i == len(strs[j]) or c != strs[j][i]:
                    return ans
            ans+=strs[0][i]
        return ans