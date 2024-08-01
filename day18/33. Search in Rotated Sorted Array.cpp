class Solution {
public:
    int get_pivot(vector<int> &nums){
        int l = 0, r = nums.size() - 1;
        if(nums[l] < nums[r]) return 0;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] > nums[r]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        
        int pivot = get_pivot(nums);
        int n = nums.size();
        int l = 0, r = nums.size() - 1;

        while(l <= r){
            int mid = l + (r - l)/2;
            int rmid = (mid + pivot)%n;

            if(nums[rmid] == target) return rmid;
            else if(nums[rmid] < target) l = mid + 1;
            else r = mid - 1; 
        }
        return -1;
    }
};