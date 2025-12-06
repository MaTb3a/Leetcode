class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        mp = {")" : "(" , "]":"[" , "}":"{"}
        for x in s:
            if x == '(' or x== '{' or x == '[':
                stk.append(x)
            else:
                if not stk or stk[-1] != mp[x]:
                    return False
                stk.pop(-1)
        return not stk
                