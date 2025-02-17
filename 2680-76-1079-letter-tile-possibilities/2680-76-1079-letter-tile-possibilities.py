from itertools import permutations

class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        vis = [False] * len(tiles)
        tiles = "".join(sorted(tiles))  
        
        def solve():
            ret = 1
            for i in range(len(tiles)):
                if vis[i] or (i > 0 and tiles[i] == tiles[i - 1] and not vis[i - 1]):
                    continue
                vis[i] = True
                ret += solve()
                vis[i] = False
            return ret
        
        return solve() - 1 

