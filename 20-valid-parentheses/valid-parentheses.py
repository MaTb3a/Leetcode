class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        mp = {")":"(" , "}":"{","]":"["}
        for x in s:
            if x == '(' or x == '{' or x == '[': # open
                stk.append(x)
            else: # close
                if not stk or (stk[-1] != mp[x]):
                    return False
                stk.pop()
        return not stk
              

