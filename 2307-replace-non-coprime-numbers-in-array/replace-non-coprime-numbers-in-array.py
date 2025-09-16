class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        def gcd(x,y):
            if y == 0:
                return x
            return gcd(y,x%y)
        
        def lcm(x,y):
            return (x*y)//gcd(x,y)
        
        last = []
        last.append(nums.pop())

        while len(nums):
            g = gcd(last[-1],nums[-1])
            if g > 1:
                nums[-1] = lcm(nums[-1],last[-1])
                last.pop()
            else:
                last.append(nums.pop())
            if len(last) == 0:
                last.append(nums.pop())
        
        return last[::-1]