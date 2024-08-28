#include <unordered_map>
using namespace std;

class Node {
public:
    int key, val;
    Node* prev;
    Node* next;
    
    Node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int cap;
    unordered_map<int, Node*> cache;
    Node *left, *right;
    
public:
    LRUCache(int capacity) : cap(capacity) {
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1; // Key not found
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);
        
        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    void insert(Node* node) {
        Node* prev = right->prev;
        Node* next = right;
        prev->next = node;
        node->prev = prev;
        node->next = next;
        next->prev = node;
    }
};
