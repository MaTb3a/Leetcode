class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        def ok(md,cars):
            for i in ranks:
                cars-= int(math.sqrt(md//i))
            return cars <= 0
        st,ed,cur,md = 1,min(ranks)*cars*cars,-1,0
        while st<=ed:
            md = (st+ed)//2
            if ok(md,cars):
                cur = md
                ed = md -1
            else:
                st = md +1
        return (cur)