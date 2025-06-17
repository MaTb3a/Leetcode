class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = defaultdict(int)
        for num in nums:
            mp[num]+=1
        pr = []
        for key,values in mp.items():
            heapq.heappush(pr,[values,key])
            if len(pr) > k:
                heapq.heappop(pr)

        ans = []
        while pr:
            ans.append(heapq.heappop(pr)[1])
        return ans