class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort()
        pre = ""
        for i in range(len(strs[0])):
            if strs[0][i] != strs[-1][i]:
                return pre
            pre+=strs[0][i]
        return pre
