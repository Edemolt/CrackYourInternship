class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char, int>> st;
        int n = colors.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push({colors[i], i});
            } else {
                while (!st.empty() && colors[i] == st.top().first) {
                    int pos = st.top().second;
                    if (neededTime[pos] < neededTime[i]) {
                        ans += neededTime[pos]; 
                        st.pop();
                    } else {
                        ans += neededTime[i]; 
                        break;
                    }
                }
                if (st.empty() || colors[i] != st.top().first) {
                    st.push({colors[i], i});
                }
            }
        }
        
        return ans;
    }
};