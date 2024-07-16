class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> countMap; // To store the frequency of mod values
        countMap[0] = 1; // Initial condition: a sum of 0 is divisible by k
        int sum = 0;
        int count = 0;
        
        for(int num : nums) {
            sum += num;
            int mod = (sum % k + k) % k; // Normalize mod value to handle negative numbers
            
            if(countMap.find(mod) != countMap.end()) {
                count += countMap[mod];
            }
            
            countMap[mod]++;
        }
        
        return count;
    }
};
