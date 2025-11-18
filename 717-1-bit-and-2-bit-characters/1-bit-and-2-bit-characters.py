class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i = 0
        while i < (len(bits)):
            if bits[i] == 1:
                i += 1
            elif i == len(bits) - 1:
                return True
            i+=1
                
        return False
        
            
    # 0 1 0
    # 1 1 1 0
    # 1 1
    # 1 1 1