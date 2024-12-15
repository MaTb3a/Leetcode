import heapq

class Solution:
    def maxAverageRatio(self, classes: list[list[int]], extraStudents: int) -> float:
        def calc_gain(x, y):
            return (x + 1) / (y + 1) - x / y

        # Max-heap using negative gain values
        pq = [(-calc_gain(x, y), x, y) for x, y in classes]
        heapq.heapify(pq)

        # Distribute extra students
        for _ in range(extraStudents):
            gain, x, y = heapq.heappop(pq)
            x, y = x + 1, y + 1
            heapq.heappush(pq, (-calc_gain(x, y), x, y))

        # Calculate the final average ratio
        total_ratio = 0
        while pq:
            _, x, y = heapq.heappop(pq)
            total_ratio += x / y

        return total_ratio / len(classes)
