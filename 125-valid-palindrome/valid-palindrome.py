class Solution:
    def isPalindrome(self, s: str) -> bool:
        #s = ''.join([c.lower() for c in s if c.isalnum()])
        s = re.sub('[^a-z0-9]','',s.lower())
        return s == s[::-1] 