class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
       
      
        def hash_vowel(s):
            return "".join( '*' if c in "aeiou" else c for c in s.lower())
        
        ans = []              
        perfect = set(wordlist)    
        cap = defaultdict(list)
        vow = defaultdict(list)

        for s in wordlist:
            cap[s.lower()].append(s) 
            vow[hash_vowel(s)].append(s)

        def solve(q):
            if q in perfect:
                return q
            lq = q.lower()
            if lq in cap:
                return cap[lq][0]
            hash_q = hash_vowel(q)
            if hash_q in vow:
                return vow[hash_q][0]
            return ""
        
        return list(map(solve,queries))
        
        
            