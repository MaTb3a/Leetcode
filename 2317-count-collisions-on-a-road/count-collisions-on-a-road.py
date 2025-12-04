class Solution:
    def countCollisions(self, directions: str) -> int:
        # R R = cnt+1
        # R S = cnt+1 + ans+=cnt
        # R L = cnt+=2 + ans+=cnt

        # S S = 0
        # S R = 0
        # S L = cnt+1 ans+1

        # L L = if RS == 1
        # L R = 0 
        # L S = 0

        n = len(directions)
        cnt,ans,RS = 0,0,0
        for i in range(n-1):
            if directions[i] == 'R':
                if directions[i+1] == 'R':
                    cnt+=1
                elif directions[i+1] == 'S':
                    ans+=cnt+1
                    cnt = 0
                elif directions[i+1] == 'L':
                    ans+=cnt+1
                    cnt = 0
                RS = True
            elif directions[i] == 'S':
                cnt = 0
                RS = True
            else: # L
                if RS:
                    ans+=1
        if directions[-1] == 'L' and RS == True:
            ans+=1
        return ans
                
