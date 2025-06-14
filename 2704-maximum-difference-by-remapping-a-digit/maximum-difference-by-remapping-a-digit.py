class Solution:
    def minMaxDifference(self, num: int) -> int:
        def max_num(num):
            replace = '9'
            for c in num:
                if c != '9':
                    replace = c
                    break
            return int(num.replace(replace,'9'))
        
        def min_num(num):
            replace = '0'
            for c in num:
                if c != '0':
                    replace = c
                    break
            return int(num.replace(replace,'0'))
        
        return max_num(str(num)) - min_num(str(num))

