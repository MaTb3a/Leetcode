class Solution:
    def canChange(self, start: str, target: str) -> bool:
        n = len(start)
        i = j = 0
        
        while i < n or j < n:
            while i < n and start[i] == '_':  # Skip '_' in start
                i += 1
            while j < n and target[j] == '_':  # Skip '_' in target
                j += 1
            
            # Both strings are fully traversed
            if i == n and j == n:
                return True
            
            # One string finishes early
            if i == n or j == n or start[i] != target[j]:
                return False
            
            # Check constraints for L and R
            if start[i] == 'L' and i < j:  # L can only move left
                return False
            if start[i] == 'R' and i > j:  # R can only move right
                return False
            
            i += 1
            j += 1
        
        return True
