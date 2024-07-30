class Solution {
public:
    int fn(vector<int> &hist){
        int n = hist.size();
        int mx = 0;
        stack<int> st;

        for(int i = 0; i <= n; i++){
            while(!(st.empty()) && (i == n || hist[st.top()] >= hist[i])){
                int height = hist[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                mx = max(mx, (height * width));
            }
            st.push(i);
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;

        int m = matrix[0].size();
        int mx = 0;
        vector<int> hist(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') hist[j] += 1;
                else hist[j] = 0;
            }

            mx = max(mx, fn(hist));
        }
        return mx;
    }
};