class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False

        has_vowel,has_consonant = False,False

        for c in word:
            if c.isalpha():
                if c.lower() in "aeiou":
                    has_vowel = True
                else:
                    has_consonant = True
            elif not c.isdigit():
                return False
        return has_vowel and has_consonant
