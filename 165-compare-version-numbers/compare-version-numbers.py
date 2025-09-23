class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        l1 = list(map(int, version1.split('.')))
        l2 = list(map(int, version2.split('.')))

        while len(l1) and len(l2):
            if int(l1[0]) > int(l2[0]):
                return 1
            if int(l1[0]) < int(l2[0]):
                return -1
            l1.pop(0)
            l2.pop(0)
        
        l1 = [x for x in l1 if x != 0]
        l2 = [x for x in l2 if x != 0]
               
        if len(l1) > len(l2):
            return 1
        if len(l1) < len(l2):
            return -1
        return 0
        