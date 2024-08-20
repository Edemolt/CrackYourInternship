class Solution {
public:
    int help(string &s, int k, char ch){
        int l = 0, r = 0, n = s.size();
        int others = 0, ans = 0;

        while(r < n){
            if( s[r] != ch) others += 1;

            if( others > k){
                if( s[l] != ch) others -= 1;
                l += 1;
            }

            if( others <= k) ans = max( ans, r - l + 1);
            r += 1;
        }
        return ans;

        
    }
    int characterReplacement(string s, int k) {
        int ans = 0;
        vector<int> done(256, 0);

        for( char ch : s){
            if(!done[ch - 'A']){
                ans  = max( ans, help(s, k, ch));
                done[ch - 'A'] = 1;
            }
        }

        return ans;
    }
};