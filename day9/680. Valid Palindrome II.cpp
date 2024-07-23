class Solution {
public:
    int check(int l, int r, string &s){
        while(l < r){
            if(s[l] != s[r]) return 0;
            l += 1;
            r -= 1;
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n-1;

        while(l < r){
            if(s[l] != s[r]){
                return max( check(l+1, r, s), check(l, r-1, s));
            }
            l += 1;
            r -= 1;
        }
        return 1;
    }
};