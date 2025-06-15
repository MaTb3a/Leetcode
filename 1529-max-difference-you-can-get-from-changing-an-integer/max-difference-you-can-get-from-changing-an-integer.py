class Solution:
    def maxDiff(self, num: int) -> int:
        
        def get_max(num):
            min_digit = '9'
            for i in range(len(num)):
                if num[i] != '9':
                    min_digit = num[i]
                    break
            return int(num.replace(min_digit,'9'))
        
        def get_min(num):
            mx = '1'
            for x in num:
                if x > '1':
                    mx = x
                    break
            if mx != num[0]:
                return int(num.replace(mx,'0'))
            return int(num.replace(num[0],'1'))

        print(get_max(str(num)))
        print(get_min(str(num)))
        return (get_max(str(num)) - get_min(str(num)))

                
