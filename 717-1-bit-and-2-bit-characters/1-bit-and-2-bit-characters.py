class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        # 1 0
        # 1 1
        i = 0
        while i < len(bits)-1:
            if bits[i] == 1:
                i+=2
            else:
                i+=1
        if i == len(bits):
            return False
        return True
        
            
    # 0 1 0
    # 1 1 1 0
    # 1 1
    # 1 1 1