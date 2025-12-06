class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        for x in s:
            if x == '(' or x == '{' or x == '[': # open
                stk.append(x)
            else: # close
                if not stk or (x == ')' and stk[-1] != '(') or (x == ']' and stk[-1] != '[') or (x == '}' and stk[-1] != '{'):
                    return False
                stk.pop()
        return not stk
              

