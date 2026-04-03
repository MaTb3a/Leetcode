class Solution {
    int calc(long long L, long long R, const vector<int>& walls) {
        if (L > R) return 0;
        auto it1 = lower_bound(walls.begin(), walls.end(), L);
        auto it2 = upper_bound(walls.begin(), walls.end(), R);
        return it2 - it1;
    }

    int solve(int i, int dir, const vector<pair<int, int>>& v, const vector<int>& walls, vector<vector<int>>& dp, int n) {
        if (i == n) return 0;
        if (dp[i][dir] != -1) return dp[i][dir];

        long long prev_reach = -3000000000LL; 
        
        if (i > 0) {
            if (dir == 0) {
                prev_reach = v[i-1].first;
            } else {
                prev_reach = min((long long)v[i-1].first + v[i-1].second, (long long)v[i].first - 1);
            }
        }

        long long left_start = max((long long)v[i].first - v[i].second, prev_reach + 1);
        int walls_left = calc(left_start, v[i].first, walls);
        int res_left = walls_left + solve(i + 1, 0, v, walls, dp, n);

        long long right_end = (long long)v[i].first + v[i].second;
        if (i + 1 < n) {
            right_end = min(right_end, (long long)v[i+1].first - 1);
        }
        int walls_right = calc(v[i].first, right_end, walls);
        int res_right = walls_right + solve(i + 1, 1, v, walls, dp, n);
        return dp[i][dir] = max(res_left, res_right);
    }

public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {robots[i], distance[i]};
        }
        
        sort(v.begin(), v.end());
        sort(walls.begin(), walls.end());

        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 0, v, walls, dp, n);
    }
};