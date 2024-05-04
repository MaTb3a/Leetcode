class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        i = 0
        j = len(people) -1
        cnt = 0
        while i <= j:
            cnt+=1
            if i == j:
                return cnt
            if people[i] + people[j] <= limit:
                i+=1
                j-=1
            else :
                j-=1
        return cnt
            