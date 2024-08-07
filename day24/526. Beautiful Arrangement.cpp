class Solution {
public:
    void find(int ind, vector<int> &v, int &count) {
        if (ind == v.size()) {
            count++;
            return;
        }
        for (int i = ind; i < v.size(); i++) {
            swap(v[ind], v[i]);
            if (v[ind] % (ind + 1) == 0 || (ind + 1) % v[ind] == 0)
                find(ind + 1, v, count);
            swap(v[ind], v[i]);  // backtrack
        }
    }

    int countArrangement(int n) {
        vector<int> v(n);
        for (int i = 1; i <= n; i++)
            v[i - 1] = i;

        int count = 0;
        find(0, v, count);
        return count;
    }
};