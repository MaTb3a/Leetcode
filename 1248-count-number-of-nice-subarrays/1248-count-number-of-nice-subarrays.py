class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        #[2,2,2,1,2,2,1,2,2,2]
        # 0 0 0 1 0 0 1 0 0 0
        # 0 0 0 1 1 1 2 2 2 2
        # 3 6
        
        cnt = 0
        ctr = 0
        odds = 0
        st = 0
        ed = 0
        n = len(nums)
        while ed < n:
            if nums[ed]&1:
                odds+=1
            if odds==k:
                ctr = 0
                while odds == k:
                    odds-=nums[st]&1
                    st+=1
                    ctr+=1
            ed+=1
            cnt+=ctr
        return cnt
        