from collections import deque

class Solution:
    def __init__(self):
        self.directions = [
            [1, 3],     # 0
            [0, 2, 4],  # 1
            [1, 5],     # 2
            [0, 4],     # 3
            [1, 3, 5],  # 4
            [2, 4]      # 5
        ]

    def slidingPuzzle(self, board):
        target = "123450"
        start = "".join(str(cell) for row in board for cell in row)
        visited = {start: 0}
        queue = deque([(start.index('0'), start)])

        while queue:
            zero_pos, current_state = queue.popleft()
            if current_state == target:
                return visited[current_state]

            for neighbor in self.directions[zero_pos]:
                new_state = list(current_state)
                new_state[zero_pos], new_state[neighbor] = new_state[neighbor], new_state[zero_pos]
                new_state_str = "".join(new_state)
                if new_state_str not in visited:
                    visited[new_state_str] = visited[current_state] + 1
                    queue.append((neighbor, new_state_str))

        return -1
