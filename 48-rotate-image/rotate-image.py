class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        matrix[:] = [list(r) for r in zip(*matrix[::-1])]