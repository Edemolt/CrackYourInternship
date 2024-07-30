class Solution {
public:
    string minWindow(string s, string t) {
        int len = 1e9, start = -1;
        int i = 0, j = 0;
        int n = s.size();

        map<char, int> mp;
        int m = t.size();
        for(int i = 0; i < m; i++) mp[t[i]]++;

        int cnt = mp.size();
        while(j < n){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0) cnt-= 1;
                while(cnt == 0){
                    if(mp.find(s[i]) != mp.end()){
                        mp[s[i]] += 1;
                        if(mp[s[i]] > 0){
                            cnt += 1;
                            if(j - i + 1 < len){
                                len = j - i + 1;
                                start = i;
                            }
                        }
                    }
                    i += 1;
                }
            }
            j++;
        }
        if(start == -1) return "";
        return s.substr(start,len);
    }
};