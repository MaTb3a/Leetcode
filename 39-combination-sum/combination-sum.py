class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        def solve(i,cur,target):
            if i >= len(candidates) or target <= 0:
                if target == 0:
                    ans.append(cur[:])
                return

            solve(i+1,cur,target)
            if target >= candidates[i]:
                cur.append(candidates[i])
                solve(i,cur,target-candidates[i])
                cur.pop()
        
        solve(0,[],target)
        return ans
                