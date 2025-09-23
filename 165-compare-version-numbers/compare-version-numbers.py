class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        l1 = version1.split('.')
        l2 = version2.split('.')

        i,j = 0,0
        while len(l1) and len(l2):
            if int(l1[i]) > int(l2[j]):
                return 1
            if int(l1[i]) < int(l2[j]):
                return -1
            l1.pop(i)
            l2.pop(j)
        
        print(l1,l2)
        while len(l1):
            if int(l1[j]) == 0:
                l1.pop(j)
            else:
                break
        
        while len(l2):
            if int(l2[j]) == 0:
                l2.pop(j)
            else :
                break
        
       # print(l1,l2)
       
        if len(l1) > len(l2):
            return 1
        if len(l1) < len(l2):
            return -1
        return 0
        