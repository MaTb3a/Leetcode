class Vertex:
    def __init__(self, vertex_id: int = None):
        self.vertex_id = vertex_id
        self.offline = False
        self.power_grid_id = -1
        if vertex_id is not None:
            self.vertex_id = vertex_id


class Graph:
    def __init__(self):
        self.adj: Dict[int, List[int]] = {}
        self.vertices: Dict[int, Vertex] = {}

    def add_vertex(self, id: int, value: Vertex):
        self.vertices[id] = value
        self.adj[id] = []

    def add_edge(self, u: int, v: int):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def get_vertex_value(self, id: int) -> Vertex:
        return self.vertices[id]

    def get_connected_vertices(self, id: int) -> List[int]:
        return self.adj[id]


class Solution:
    def traverse(
        self, u: Vertex, power_grid_id: int, power_grid: List[int], graph: Graph
    ):
        u.power_grid_id = power_grid_id
        heapq.heappush(power_grid, u.vertex_id)
        for vid in graph.get_connected_vertices(u.vertex_id):
            v = graph.get_vertex_value(vid)
            if v.power_grid_id == -1:
                self.traverse(v, power_grid_id, power_grid, graph)

    def processQueries(
        self, c: int, connections: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        graph = Graph()
        for i in range(c):
            v = Vertex(i + 1)
            graph.add_vertex(i + 1, v)

        for conn in connections:
            graph.add_edge(conn[0], conn[1])

        power_grids = []
        power_grid_id = 0

        for i in range(1, c + 1):
            v = graph.get_vertex_value(i)
            if v.power_grid_id == -1:
                power_grid = []
                self.traverse(v, power_grid_id, power_grid, graph)
                power_grids.append(power_grid)
                power_grid_id += 1

        ans = []
        for q in queries:
            op, x = q[0], q[1]
            if op == 1:
                vertex = graph.get_vertex_value(x)
                if not vertex.offline:
                    ans.append(x)
                else:
                    power_grid = power_grids[vertex.power_grid_id]
                    while (
                        power_grid
                        and graph.get_vertex_value(power_grid[0]).offline
                    ):
                        heapq.heappop(power_grid)
                    ans.append(power_grid[0] if power_grid else -1)
            elif op == 2:
                graph.get_vertex_value(x).offline = True

        return ans