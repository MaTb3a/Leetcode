class Solution(object):
    def differByOneChar(self, word1, word2):
        if len(word1) != len(word2):
            return False
        diffCount = 0
        for c1, c2 in zip(word1, word2):
            if c1 != c2:
                diffCount += 1
        return diffCount == 1

    def getWordsInLongestSubsequence(self, words, groups):
        n = len(groups)
        dp = [1] * n
        parent = [-1] * n
        maxi = 0
        for i in range(n):
            for j in range(i):
                if groups[i] != groups[j] and \
                   self.differByOneChar(words[i], words[j]) and \
                   dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
                    parent[i] = j
            if dp[i] > maxi:
                maxi = dp[i]
        result = []
        for i in range(n):
            if dp[i] == maxi:
                while i != -1:
                    result.append(words[i])
                    i = parent[i]
                break
        return result[::-1]