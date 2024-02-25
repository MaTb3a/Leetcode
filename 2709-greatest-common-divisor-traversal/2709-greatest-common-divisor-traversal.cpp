class Solution {
    // Function to find the root of a set using path compression
    int getf(vector<int> &f, int x) {
        return f[x] == x ? x : (f[x] = getf(f, f[x]));
    }
    
    // Function to merge two sets and update the frequency
    void merge(vector<int> &f, vector<int> &num, int x, int y) {
        x = getf(f, x);
        y = getf(f, y);
        if (x == y) {
            return;
        }
        if (num[x] < num[y]) {
            swap(x, y);
        }
        f[y] = x;
        num[x] += num[y];
    }
public:
    // Main function to check if it is possible to traverse all pairs
    bool canTraverseAllPairs(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) {
            return true;
        }
        
        // Initialize Union-Find data structures
        vector<int> f(n), num(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
            num[i] = 1;
        }
        
        // Map to store the first index encountered for each prime factor
        unordered_map<int, int> have;
        
        // Iterate through the array to find common prime factors and perform Union-Find
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (x == 1) {
                return false;
            }
            
            // Iterate through prime factors of x
            for (int d = 2; d * d <= x; ++d) {
                if (x % d == 0) {
                    // If the prime factor is encountered before, merge the sets
                    if (have.count(d)) {
                        merge(f, num, i, have[d]);
                    } else {
                        // Otherwise, store the index for this prime factor
                        have[d] = i;
                    }
                    while (x % d == 0) {
                        x /= d;
                    } 
                }
            }
            
            // Handle the case where x itself is a prime factor
            if (x > 1) {
                if (have.count(x)) {
                    merge(f, num, i, have[x]);
                } else {
                    have[x] = i;
                }
            }
        }
        
        // Check if all indices belong to the same connected component
        return num[getf(f, 0)] == n;
    }
};
