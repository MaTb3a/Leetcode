class Solution:
    def solve(self, s: str, locked: str, forward: bool) -> bool:
        cnt, magic = 0, 0
        n = len(s)

        for i in range(n):
            idx = i if forward else n - i - 1
            if locked[idx] == '0':
                magic += 1
                continue

            if (s[idx] == '(' and forward) or (s[idx] == ')' and not forward):
                cnt += 1
            else:
                if cnt > 0:
                    cnt -= 1
                elif magic > 0:
                    magic -= 1
                else:
                    return False

        return True

    def canBeValid(self, s: str, locked: str) -> bool:
        if len(s) % 2 != 0:
            return False
        return self.solve(s, locked, True) and self.solve(s, locked, False)
