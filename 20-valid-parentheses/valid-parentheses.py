class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        for x in s:
            if x == '(' or x== '{' or x == '[':
                stk.append(x)
            else:
                if not stk or (x == ')' and stk[-1] != '(') or (x == ']' and stk[-1] != '[') or (x == '}' and stk[-1] != '{'):
                    return False
                stk.pop(-1)
        return not stk
                