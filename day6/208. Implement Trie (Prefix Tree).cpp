class Trie {
public:
    struct Node{
        Node * links[26] = {};
        int flag = 0;

        int contains_key(char ch){
            return links[ch - 'a'] != NULL;
        }

        Node * get(char ch){
            return links[ch - 'a'];
        }

        void put_char(char ch, Node * node){
            links[ch - 'a'] = node;
        }

        void set_flag(){
            flag = 1;
        }

        int is_flag_set(){
            return flag;
        }
    };
    Node * root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node * temp = root;
        for(char ch : word){
            if(!(temp->contains_key(ch))) temp->put_char(ch, new Node());
            temp = temp->get(ch);
        }
        temp->set_flag();
    }
    
    bool search(string word) {
        Node * temp = root; 
        for(char ch : word){
            if(!(temp->contains_key(ch))) return 0;
            temp = temp->get(ch);
        }
        return temp->is_flag_set();
    }
    
    bool startsWith(string prefix) {
        Node * temp = root; 
        for(char ch : prefix){
            if(!(temp->contains_key(ch))) return 0;
            temp = temp->get(ch);
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */