class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0, total = 0, maxFruits = 0;

        for (int right = 0; right < n; ++right) {
            total += fruits[right][1];

            while (left <= right) {
                int leftPos = fruits[left][0];
                int rightPos = fruits[right][0];

                int dist = min(
                    abs(startPos - leftPos) + (rightPos - leftPos),
                    abs(startPos - rightPos) + (rightPos - leftPos)
                );

                if (dist <= k) break;

                total -= fruits[left][1];
                ++left;
            }

            maxFruits = max(maxFruits, total);
        }

        return maxFruits;
    }
};