class Solution:
    def reverseWords(self, s: str) -> str:
        lst = []
        word = ''
        for c in s:
            if c == ' ':
                if word:
                    lst.append(word)
                word = ''
            else:
                word+=c
        if word:
            lst.append(word)
        ans = ''
        for x in lst[::-1]:
            ans+= x + ' '
        return ans[:-1]