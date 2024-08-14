class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);  
        
        for(char ch: s) 
            v[ch - 'a']++;
        
        sort(v.rbegin(), v.rend());  
        
        int deletions = 0;
        for(int i = 1; i < 26 && v[i] > 0; i++) {
            if(v[i] >= v[i - 1]) {
                int newFreq = max(0, v[i - 1] - 1);
                deletions += v[i] - newFreq;
                v[i] = newFreq;
            }
        }
        
        return deletions;
    }
};
