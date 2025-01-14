class Solution:
    def findThePrefixCommonArray(self, A: list[int], B: list[int]) -> list[int]:
        vis = [0] * 51
        vis2 = [0] * 51
        result = []

        for i in range(len(A)):
            vis[A[i]] = 1
            vis2[B[i]] = 1
            count = sum(vis[j] & vis2[j] for j in range(51))
            result.append(count)

        return result
