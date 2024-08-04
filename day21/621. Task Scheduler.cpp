class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);
        int mx = 0;
        int cnt = 0;
        int sz = tasks.size();
        for(char ch : tasks){
            v[ch - 'A']++;
            mx = max(mx, v[ch - 'A']);
        }

        for(int i = 0; i < 26; i++){
            if(v[i] == mx) cnt += 1;
        }

        return max( (mx - 1) * (n + 1) + cnt, sz);


    }
};