class Solution:
    def minOperations(self, boxes: str) -> list[int]:
        n = len(boxes)
        op = 0
        L, R = 0, 0

        for i in range(n):
            if boxes[i] == '1':
                op += i
                R += 1

        v = [0] * n
        for i in range(n):
            v[i] = op
            if boxes[i] == '1':
                L += 1
                R -= 1
            op += -R + L

        return v
