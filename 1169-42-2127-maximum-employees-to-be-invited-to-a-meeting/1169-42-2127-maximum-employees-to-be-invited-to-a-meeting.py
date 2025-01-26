from collections import deque

class Solution:
    def maximumInvitations(self, favorite: list[int]) -> int:
        n = len(favorite)
        deg = [0] * n
        for fav in favorite:
            deg[fav] += 1

        q = deque(i for i in range(n) if deg[i] == 0)
        chain = [1] * n

        while q:
            x = q.popleft()
            y = favorite[x]
            chain[y] = max(chain[y], chain[x] + 1)
            deg[y] -= 1
            if deg[y] == 0:
                q.append(y)

        mx = meetings = 0
        for i in range(n):
            if deg[i] == 0:
                continue
            cur, length = i, 0
            while deg[cur]:
                length += 1
                deg[cur] = 0
                cur = favorite[cur]
            if length > 2:
                mx = max(mx, length)
            else:
                meetings += chain[i] + chain[favorite[i]]

        return max(mx, meetings)
