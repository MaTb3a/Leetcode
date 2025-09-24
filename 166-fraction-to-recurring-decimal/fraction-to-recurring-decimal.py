class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"

        res = []
        if (numerator < 0) ^ (denominator < 0):
            res.append('-')

        n = abs(numerator)
        d = abs(denominator)

        res.append(str(n // d))
        rem = n % d
        if rem == 0:
            return ''.join(res)

        res.append('.')
        seen = {}

        while rem:
            if rem in seen:
                idx = seen[rem]
                res.insert(idx, '(')
                res.append(')')
                break
            seen[rem] = len(res)
            rem *= 10
            res.append(str(rem // d))
            rem = rem % d

        return ''.join(res)