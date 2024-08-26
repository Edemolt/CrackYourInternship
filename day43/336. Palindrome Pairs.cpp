class TRIE {
public:
    struct Node {
        Node* arr[26] = {};
        int flag = 0;

        int contains_char(char ch) {
            return arr[ch - 'a'] != NULL;
        }

        void put(Node* new_node, char ch) {
            arr[ch - 'a'] = new_node;
        }

        Node* get_next(char ch) {
            return arr[ch - 'a'];
        }

        void set_flag() {
            flag = 1;
        }

        int is_flag_set() {
            return flag;
        }
    };

    Node* root = new Node();

    void insert(string word) {
        Node* temp = root;

        for (char i : word) {
            if (!(temp->contains_char(i))) {
                Node* new_node = new Node();
                temp->put(new_node, i);
            }
            temp = temp->get_next(i);
        }

        temp->set_flag();
    }

    int search(string word) {
        Node* temp = root;

        for (char i : word) {
            if (!temp->contains_char(i)) return 0;
            temp = temp->get_next(i);
        }
        return temp->is_flag_set();
    }

    int starts_with(string word) {
        Node* temp = root;
        for (char i : word) {
            if (!temp->contains_char(i)) return 0;
            temp = temp->get_next(i);
        }
        return 1;
    }
};

class Solution {
public:
    int isPalindrome(string &s){
        int n = s.size();
        int l = 0, r = n-1;
        while( l < r){
            if(s[l] != s[r]) return 0;
            l += 1;
            r -= 1;
        }
        return 1;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordMap;  
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); i++) {
            string reversedWord = words[i];
            reverse(reversedWord.begin(), reversedWord.end());
            wordMap[reversedWord] = i;
        }
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int len = word.size();
            
            for (int j = 0; j <= len; j++) {
                string left = word.substr(0, j);
                string right = word.substr(j);
                if (isPalindrome(left)) {
                    auto it = wordMap.find(right);
                    if (it != wordMap.end() && it->second != i) {
                        result.push_back({it->second, i});
                    }
                }
                if (j != len && isPalindrome(right)) {
                    auto it = wordMap.find(left);
                    if (it != wordMap.end() && it->second != i) {
                        result.push_back({i, it->second});
                    }
                }
            }
        }
        
        return result;
    }
};