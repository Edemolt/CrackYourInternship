class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, char> > q;

        set<string> s(wordList.begin(), wordList.end());

        q.push({beginWord, 1});
        s.erase(beginWord);

        while(!(q.empty())){
            string node = q.front().first;
            int pos = q.front().second;
            if(node == endWord)
                return pos;
            int n = node.size();
            q.pop();

            for(int i = 0; i < n; i++){
                char original = node[i];

                for(char j = 'a'; j <= 'z'; j++){
                    node[i] = j;
                    if(s.find(node) != s.end()){
                        q.push({node,pos+1});
                        s.erase(node);
                    }
                    node[i] = original;
                }
            }
        }

        return 0;


    }
};