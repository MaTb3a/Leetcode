class Solution:
    def sortVowels(self, s: str) -> str:
        def is_vowel(c):
            c = c.lower()
            if c == 'a' or c == 'i' or c == 'u' or c == 'e' or c == 'o':
                return True
            return False

        vowels = []
        for c in s:
            if is_vowel(c):
                vowels.append(c)

        vowels.sort()
        s = list(s)
        j = 0
        for i in range(len(s)):
            if is_vowel(s[i]):
                s[i] = vowels[j]
                j+=1
        
        return ''.join(s)