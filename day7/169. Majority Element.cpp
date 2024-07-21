class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int cnt = 0, ele;
       for(auto &itr : nums){
           if(cnt == 0){
               cnt += 1;
               ele = itr;
           }
           else if(ele == itr) cnt += 1;
           else cnt -= 1;
       } 

       int cnt1 = 0;

       for(auto &itr : nums){
           if(ele == itr) cnt1 ++;
       }

       if(cnt1 > (nums.size()/2)) return ele;
       return -1;
    }
};