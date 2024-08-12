class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> s;
        int res = 0;

        int n = arr.size();

        for(int i = 0; i < n; i++){

            while(!(s.empty()) && s.top() <= arr[i]){
                int mid = s.top();
                s.pop();
                if(!(s.empty())){
                    res += mid * min(s.top(), arr[i]);
                }else res += mid * arr[i];
            }
            s.push(arr[i]);
        }

        while(s.size() > 1){
            int mid = s.top();
            s.pop();
            res += mid * s.top(); 
        }
        return res;
    }
};