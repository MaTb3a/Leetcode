class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        i = 1
        while i < len(words):
            a = (words[i])
            b = (words[i-1])
            if sorted(a) == sorted(b):
                words.pop(i)
            else:
                i+=1
        return words
