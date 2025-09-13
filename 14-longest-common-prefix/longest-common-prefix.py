class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        s_len = 1
        ans = ""
        for i in range(len(strs[0])):
            common = True
            for j in range(1,len(strs)):
                if i < len(strs[j]) and strs[j][i] == strs[j-1][i]:
                    continue
                common = False
                break

            if not common:
                return ans
            ans+=strs[0][i]
        return ans