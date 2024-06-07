class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        set_dec = set(dictionary)
        
        def get(word):
            for i in range(1,len(word)+1):
                if word[:i] in set_dec:
                    return word[:i]
            return word
        lst = sentence.split()
        ans = [get(word) for word in lst]
        return ' '.join(ans)
