class Solution:
    def clearDigits(self, s: str) -> str:
        stack = []
        for ch in s:
            if ch.isdigit():
                if stack:
                    stack.pop()
            else:
                stack.append(ch)
        return ''.join(stack)
