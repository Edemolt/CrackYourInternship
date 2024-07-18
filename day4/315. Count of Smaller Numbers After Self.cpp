#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct BIT {
    vector<int> bit;
    int n;
    BIT() {
        n = 1e4 * 2 + 1;
        bit.assign(n, 0);
    }
    
    void update(int idx, int val) {
        while (idx < n) {
            bit[idx] += val;
            idx = idx | (idx + 1);
        }
    }
    
    int query(int idx) {
        int s = 0;
        while (idx >= 0) {
            s += bit[idx];
            idx = (idx & (idx + 1)) - 1;
        }
        return s;
    }
};

int getidx(int idx) {
    return idx + 1e4;
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        BIT bit;
        
        // Process from right to left
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans.push_back(bit.query(getidx(nums[i] - 1)));
            bit.update(getidx(nums[i]), 1);
        }
        
        // Reverse the result since we processed from right to left
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
