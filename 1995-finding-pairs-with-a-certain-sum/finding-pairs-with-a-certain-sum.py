class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.dic = Counter(nums2)
        self.nums1 = nums1
        self.nums2 = nums2
        

    def add(self, index: int, val: int) -> None:
        self.dic[self.nums2[index]]-=1
        self.nums2[index]+=val
        self.dic[self.nums2[index]]+=1


    def count(self, tot: int) -> int:
        cnt = 0
        for x in self.nums1:
            cnt+=self.dic[tot-x]
        return cnt
        


# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)