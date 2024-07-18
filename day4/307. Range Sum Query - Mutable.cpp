class BIT{
    vector<int> bit;
    int n;
    public:
        BIT(int n){
            this->n = n;
            bit.assign(n+1,0);
        }

        void updatutil(int ind, int val){
            ind += 1;
            while(ind <= n){
                bit[ind] += val;
                ind += (ind &(-ind));
            }
        }

        void built(vector<int> &arr){
            for(int i = 0; i < n; i++) updatutil(i, arr[i]);
        }

        int findsum(int ind){
            int ans = 0;
            ind += 1;

            while(ind > 0){
                ans += bit[ind];
                ind -= (ind & (-ind));
            }
            return ans;
        }

        int sumrange(int l, int r){
            return findsum(r) - findsum(l-1);
        }

        void update(vector<int> &arr, int ind, int val){
            int diff = val - arr[ind];
            arr[ind] = val;
            updatutil(ind, diff);
        }
};

class NumArray {
public:
    BIT * bit;
    vector<int> arr;
    int n;
    NumArray(vector<int>& nums) {
        this->arr = nums;
        bit = new BIT(nums.size());
        bit->built(arr);
    }
    
    void update(int index, int val) {
        bit->update(arr, index, val);
    }
    
    int sumRange(int left, int right) {
        return bit->sumrange(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */