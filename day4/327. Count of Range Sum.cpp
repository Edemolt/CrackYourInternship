class BIT {
    vector<int> bit;
    int n;
public:
    BIT(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void updateutil(int ind, int val) {
        ind += 1;
        while (ind <= n) {
            bit[ind] += val;
            ind += (ind & (-ind));
        }
    }

    int findsum(int ind) {
        int sum = 0;
        ind += 1;
        while (ind > 0) {
            sum += bit[ind];
            ind -= (ind & (-ind));
        }
        return sum;
    }

    int sumrange(int l, int r) {
        return findsum(r) - findsum(l - 1);
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if (n == 0) return 0;

        // Step 1: Calculate prefix sums
        vector<long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Step 2: Coordinate compression
        set<long> all_numbers(prefix.begin(), prefix.end());
        for (long x : prefix) {
            all_numbers.insert(x - lower);
            all_numbers.insert(x - upper);
        }

        map<long, int> mp;
        int rank = 0;
        for (long itr : all_numbers) {
            mp[itr] = rank++;
        }

        // Step 3: Use BIT to count range sums
        BIT bit(mp.size());
        int count = 0;

        for (long x : prefix) {
            int left = mp[x - upper];
            int right = mp[x - lower];
            count += bit.sumrange(left, right);
            bit.updateutil(mp[x], 1);
        }

        return count;
    }
};
