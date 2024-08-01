class Solution {
public:
    int can(vector<int> &nums, int n, int mid, int k){
        int cnt = 1, sum = 0;
        for(int i = 0; i < n; i++){
            if(sum + nums[i] > mid){
                cnt += 1;
                sum = nums[i];
                if(cnt > k) return 0;
            }else sum += nums[i];
        }
        return 1;
    }
    int splitArray(vector<int>& nums, int k) {
        int start = -1e9, end = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            end += nums[i];
            start = max(start, nums[i]);
        }
        int ans = end;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(can(nums, n, mid, k)){
                ans = mid;
                end = mid - 1;
            }else start = mid +1;
        }
        return ans;
    }
};