class Solution {
public:
    vector<vector<int>> memo;
    int n;
    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int dp(int remain, int square) {
        if (remain == 0) {
            return 1;
        }
        
        if (memo[remain][square] != 0) {
            return memo[remain][square];
        }
        
        int ans = 0;
        for (int nextSquare : jumps[square]) {
            ans = (ans + dp(remain - 1, nextSquare)) % MOD;
        }
        
        memo[remain][square] = ans;
        return ans;
    }
    
    int knightDialer(int n) {
        this->n = n;
        memo = vector(n + 1, vector(10, 0));
        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + dp(n - 1, square)) % MOD;
        }
        
        return ans;
    }
};