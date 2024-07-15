class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3,0);
        for(auto &itr : nums) v[itr] += 1;
        int k = 0;
        for(int i = 0; i < 3; i++){
            while(v[i]){
                nums[k] = i;
                v[i] -= 1;
                k += 1;
            }
        }
    }
};