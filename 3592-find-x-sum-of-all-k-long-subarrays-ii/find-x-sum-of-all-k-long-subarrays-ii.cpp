
long long result;
set<pair<int, int>> small;
set<pair<int, int>> large;
map<int, int> freq;

void insertIntoSet(pair<int, int> p, int x) {
    if (large.size() < x || *(large.begin()) < p) {

        result += p.first * 1LL * p.second;
        large.insert(p);

        if (large.size() > x) {

            auto it = *large.begin();
            result -= it.first * 1LL * it.second;
            large.erase(it);
            small.insert(it);
        }

    } else {
        small.insert(p);
    }
}

void removeFromSet(pair<int, int> p) {

    if (p >= *(large.begin())) {
        result -= p.first * 1LL * p.second;
        large.erase(p);

        if (small.size() > 0) {
            auto it = *small.rbegin();
            result += it.first * 1LL * it.second;
            small.erase(it);
            large.insert(it);
        }

    } else {
        small.erase(p);
    }
}

void insert(int num, int x) {
    if (freq[num]) {
        removeFromSet({freq[num], num});
    }
    freq[num]++;
    insertIntoSet({freq[num], num}, x);
}

void remove(int num, int x) {
    removeFromSet({freq[num], num});
    freq[num]--;
    if (freq[num]) {
        insertIntoSet({freq[num], num}, x);
    }
}

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        result = 0;
        small.clear();
        large.clear();
        freq.clear();

        vector<long long> ans;
        for (int i = 0; i < nums.size(); ++i) {
            insert(nums[i], x);
            if (i >= k) {
                remove(nums[i - k], x);
            }
            if (i >= k - 1) {
                ans.push_back(result);
            }
        }
        return ans;
    }
};