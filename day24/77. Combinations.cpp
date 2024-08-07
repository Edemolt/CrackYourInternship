class Solution {
public:
    void solve(int ind, int n, int k, vector<int> &temp, set<vector<int> > &ans){
        if(ind > n + 1) return ;
        if(temp.size() == k){
            ans.insert(temp);
            return;
        }

        temp.push_back(ind);
        solve(ind + 1, n, k, temp, ans);
        temp.pop_back();
        solve(ind + 1, n, k, temp, ans);
    }
    vector<vector<int>> combine(int n, int k) {
        set<vector<int> > ans;
        vector<int> temp;
        solve(1, n, k, temp, ans);
        return vector<vector<int> >(ans.begin(), ans.end());
    }
};