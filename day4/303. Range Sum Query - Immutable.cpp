class BIT{
    vector<int> bit;
    int n;
    public:
        BIT(int n){
            this->n = n;
            bit.assign(n+1, 0);
        }

        void update_util(int ind, int val){
            ind += 1;
            while(ind <= n){
                bit[ind] += val;
                ind += (ind & (-ind));
            }
        }

        void build(vector<int> &arr){
            for(int i = 0; i < n; i++) update_util(i, arr[i]);
        }

        int find_sum(int ind){
            int ans = 0;
            ind += 1;
            while(ind > 0){
                ans += bit[ind];
                ind -= (ind & (-ind));
            }
            return ans;
        }

        int find_range_sum(int l, int r){
            return find_sum(r) - find_sum(l-1);
        }
};

class NumArray {
public:
    BIT * bit;
    vector<int> nums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        bit = new BIT(nums.size());
        bit->build(nums);
    }
    
    int sumRange(int left, int right) {
        return bit->find_range_sum(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */