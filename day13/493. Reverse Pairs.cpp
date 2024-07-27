class Solution {
public:
    int fn(int l, int r, vector<int> &nums){
        if(l >= r) return 0;

        int mid = (l + r)/2;

        int cnt = fn(l, mid, nums) + fn(mid + 1, r, nums);

        int j = mid + 1;
        for(int i = l; i <= mid; i++){
            while(j <= r && nums[i] > 2ll * nums[j]) j += 1;
            cnt += ( j - ( mid + 1));
        }

        vector<int> sorted;
        int i = l; 
        j = mid + 1;

        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]) sorted.push_back(nums[i++]);
            else sorted.push_back(nums[j++]);
        }

        while(i <= mid) sorted.push_back(nums[i++]);
        while(j <= r) sorted.push_back(nums[j++]);

        for(int k = l; k <= r; k++){
            nums[k] = sorted[k - l];
        }
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size() - 1;
        return fn(0, n, nums);
    }
};