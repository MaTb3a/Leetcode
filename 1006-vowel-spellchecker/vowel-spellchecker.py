class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
       
        def is_vowel(c):
            return c == 'a' or c == 'i' or c == 'e' or c == 'u' or c == 'o'
        
        def hashed_string(s):
            temp_s = s.lower()
            hashed_s = ""
            for c in temp_s:
                if is_vowel(c):
                    hashed_s+='*'
                else:
                    hashed_s+=c
            return hashed_s
        
        ans = []              
        wordlist_exist = set()    
        wordlist_capitalization = defaultdict(list)
        wordlist_vowel_error = defaultdict(list)

        for s in wordlist:
            wordlist_exist.add(s)
            wordlist_capitalization[s.lower()].append(s) 
            wordlist_vowel_error[hashed_string(s)].append(s)


      
        for s in queries:
            if s in wordlist_exist:
                ans.append(s)
            elif s.lower() in wordlist_capitalization:
                val = wordlist_capitalization[s.lower()][0]
                ans.append(val)
            elif hashed_string(s) in wordlist_vowel_error:
                val = wordlist_vowel_error[hashed_string(s)][0]
                ans.append(val)
            else:
                ans.append("")
        
        return ans
            