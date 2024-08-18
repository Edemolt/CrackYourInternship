class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char> > pq;
        vector<int> v(26, 0);

        for(char ch : s) v[ch - 'a'] += 1;

        for(int i = 0; i < 26; i++){
            if(v[i] != 0) pq.push({v[i], 'a' + i});
        }

        string str = "";
        pair<int, char> prev = {-1, '$'};
        while(!(pq.empty())){
            auto it1 = pq.top();
            pq.pop();

            str.push_back(it1.second);
            
            if(prev.first > 0) pq.push(prev);

            it1.first -= 1;
            prev = it1;
        }

        if(str.size() == s.size()) return str;
        return "";
    }
};