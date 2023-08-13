 /**
  * A trie or prefix tree is a tree data structure used to efficietly
  * store and retrieve keys in a dataset of strings. There are
  * various applications of this data structure, such as autocomplete
  * and spellchecker.
  *
  * Implement the trie class:
  *     Trie() - initializes the trie object
  *     void insert(string word) inserts the string word into the trie
  *     boolean search(String word) returns true if the string word is
  *         in the trie (i.e., was inserted before), and false otherwise
  *     boolean startsWith(String prefix) returns true if there is a
  *         previously inserted string word that has the prefix prefix,
  *         and false otherwise */

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
// a b c d e f g h i j k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
// 'a' == 97

class TrieNode {
public:
    bool is_end;
    vector<TrieNode*> children;
    
    TrieNode() : is_end(false), children(26, nullptr) {}
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->is_end = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return node->is_end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c - 'a']) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
