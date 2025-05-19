class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        mp = {}
        for i in range(len(row)):
            mp[row[i]] = i

        def get_couple(current,currentIdx,need):
            needIdx = mp[need]
            row[currentIdx],row[needIdx] = row[needIdx],row[currentIdx]
            mp[current] = needIdx

        cnt = 0
        for i in range(0,len(row),2):
            if row[i] > row[i+1]:
                row[i],row[i+1] = row[i+1],row[i]
            if row[i] &1:
                if row[i+1]!= row[i]-1:
                    cnt+=1
                    get_couple(row[i+1],i+1,row[i]-1)
            else:
                if row[i+1] != row[i]+1:
                    cnt+=1
                    get_couple(row[i+1],i+1,row[i]+1)
            
        return cnt

                