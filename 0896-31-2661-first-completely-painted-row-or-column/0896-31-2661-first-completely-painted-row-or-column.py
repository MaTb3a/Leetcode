class Solution:
    def firstCompleteIndex(self, arr, mat):
        n, m = len(mat), len(mat[0])
        idx = [0] * (len(arr) + 1)
        
        for i in range(len(arr)):
            idx[arr[i]] = i
        
        ans = float('inf')
        
        # Check rows
        for i in range(n):
            mx = 0
            for j in range(m):
                mx = max(mx, idx[mat[i][j]])
            ans = min(ans, mx)
        
        # Check columns
        for i in range(m):
            mx = 0
            for j in range(n):
                mx = max(mx, idx[mat[j][i]])
            ans = min(ans, mx)
        
        return ans
