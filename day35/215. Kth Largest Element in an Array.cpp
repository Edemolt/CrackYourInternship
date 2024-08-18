class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> pq;

        for(int num : nums) pq.push(num);

        while(k > 1){
            pq.pop();
            k -= 1;
        }
        return pq.top();
    }
};