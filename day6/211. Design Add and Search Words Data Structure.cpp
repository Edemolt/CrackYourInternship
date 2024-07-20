class WordDictionary
{
public:
    struct Node
    {
        Node *arr[27] = {};
        int flag = 0;

        int contains_char(char ch)
        {
            if (ch == '.')
                return 1;
            return arr[ch - 'a'] != NULL;
        }

    void put_char(char ch, Node *newnode)
        {
            if (ch == '.')
                arr[26] = newnode;
             else arr[ch - 'a'] = newnode;
            }

         Node *get_next(char ch)
        {
            if (ch == '.')
                return arr[26];
             else return arr[ch - 'a'];
        }

         void set_flag()
        {
             flag = 1;
        }

         int is_flag_set()
        {
             return flag == 1;
        }
        
    };
    Node *root;
     WordDictionary()
    {
         root = new Node();
    }
    
void addWord(string word)
    {
         Node *temp = root;

         for (char ch : word)
        {
             if (!(temp->contains_char(ch)))
            {
                 Node *newtemp = new Node();
                 temp->put_char(ch, newtemp);
            }
             temp = temp->get_next(ch);
            }
         temp->set_flag();
        
    }
    bool searchHelper(const string &word, int index, Node *node)
    {
        if (index == word.length())
        {
            return node->is_flag_set();
        }

        char ch = word[index];
        if (ch == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->arr[i] &&
                    searchHelper(word, index + 1, node->arr[i]))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            if (!node->contains_char(ch))
            {
                return false;
            }
            return searchHelper(word, index + 1, node->get_next(ch));
        }
    }
     bool search(string word) { return searchHelper(word, 0, root); }
};