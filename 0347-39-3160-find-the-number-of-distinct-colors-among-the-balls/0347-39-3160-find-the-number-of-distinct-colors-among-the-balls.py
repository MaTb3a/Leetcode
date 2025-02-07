class Solution:
    def queryResults(self, limit, queries):
        n = len(queries)
        result = [0] * n
        ball_color_map = {}
        color_count = {}

        for i, (ball, color) in enumerate(queries):
            if ball in ball_color_map:
                old_color = ball_color_map[ball]
                color_count[old_color] -= 1
                if color_count[old_color] == 0:
                    del color_count[old_color]

            color_count[color] = color_count.get(color, 0) + 1
            ball_color_map[ball] = color
            result[i] = len(color_count)

        return result
