class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        n = len(word)
        if numFriends == 1:
            return word
        sz = n - numFriends + 1
        ans = word[:sz]
        ch = max(word)

        for i in range(len(word)):
            if word[i] == ch:
                sub = word[i:min(len(word),i+sz)]
                if sub > ans:
                    ans = sub
        return ans
