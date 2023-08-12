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

class Trie {
private:
    Trie *children[26]; // array of 26 pointers to TrieNodes
    bool isWord;            // true

public:
    Trie() {
        isWord = false;
    }

    void insert(string word) {
        Trie *iter;
        
        for (int i = 0; i < word.size(); ++i) {
            iter->children[word[i]-'a']
        }
    }

    bool search(string word) {
        int size = word.size();
        Trie *iter;

        for (int i = 0; i < size; ++i) {
            iter = iter->children[word[i]-'a'];
            if (!iter->isWord)
                return false;
        }
        
        // might need check here to see if additional characters added?
        return true;
    }

    bool startsWith(string prefix) {
        int size = prefix.size();
        Trie *iter;

        for (int i = 0; i < size; ++i) {
            iter = iter->children[prefix[i]-'a'];
            if (!iter->isWord)
                return false;
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
