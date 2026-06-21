class Solution:
    def intToRoman(self, num: int) -> str:
        
        dic = {
            1000:            'M',
            900:            'CM',
            500:             'D',
            400:            'CD',
            100:             'C',
            90:             'XC',
            50:              'L',
            40:             'XL',
            10:              'X',
            9:              'IX',
            5:               'V',
            4:              'IV',
            1:               'I'
        }
        
        ans = ""
        for k,v in dic.items():
            x = num // k
            ans+= v*x
            num -= x*k

        return ans


