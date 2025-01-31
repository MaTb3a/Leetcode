import java.util.*;

class Solution {
    int n;
    int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    private int dfs(int x, int y, int[][] grid, int islandId) {
        if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 1) return 0;
        grid[x][y] = islandId;
        int size = 1;
        for (int[] dir : directions) {
            size += dfs(x + dir[0], y + dir[1], grid, islandId);
        }
        return size;
    }

    public int largestIsland(int[][] grid) {
        n = grid.length;
        Map<Integer, Integer> islandSizes = new HashMap<>();
        int islandId = 2, maxIsland = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j, grid, islandId);
                    islandSizes.put(islandId, size);
                    maxIsland = Math.max(maxIsland, size);
                    islandId++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    Set<Integer> uniqueIslands = new HashSet<>();
                    for (int[] dir : directions) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] > 1) {
                            uniqueIslands.add(grid[ni][nj]);
                        }
                    }
                    int newSize = 1;
                    for (int id : uniqueIslands) {
                        newSize += islandSizes.get(id);
                    }
                    maxIsland = Math.max(maxIsland, newSize);
                }
            }
        }

        return maxIsland;
    }
}
