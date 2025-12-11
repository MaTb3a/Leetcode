class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        X = defaultdict(list)
        Y = defaultdict(list)
        for x,y in buildings:
            X[x].append(y)
            Y[y].append(x)
        
        for x_key in X:
            X[x_key].sort()
        for y_key in Y:
            Y[y_key].sort()
        
        cnt = 0
        for x,y in buildings:
            ys = X[x]
            xs = Y[y]
            if xs[0] < x and xs[-1] > x and ys[0] < y and ys[-1] > y:
                cnt+=1
        return cnt

