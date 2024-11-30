from collections import defaultdict, deque

class Solution:
    def validArrangement(self, pairs):
        # Step 1: Build the adjacency list and calculate in-degrees and out-degrees
        adj = defaultdict(deque)
        in_degree = defaultdict(int)
        out_degree = defaultdict(int)

        for u, v in pairs:
            adj[u].append(v)
            out_degree[u] += 1
            in_degree[v] += 1

        # Step 2: Find the starting node for Eulerian path
        start = pairs[0][0]
        for node in out_degree:
            if out_degree[node] - in_degree[node] == 1:
                start = node
                break

        # Step 3: Eulerian path using Hierholzer's algorithm
        path = []

        def euler(node):
            while adj[node]:
                next_node = adj[node].pop()
                euler(next_node)
            path.append(node)

        euler(start)

        # Step 4: Build the result
        path.reverse()
        return [[path[i], path[i + 1]] for i in range(len(path) - 1)]
