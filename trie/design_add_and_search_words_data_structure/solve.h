 /**
  * Design a data structure that supports adding new words and finding
  * if a string matches any previously added string.
  *
  * Implement the WordDictionary class:
  *
  * WordDictionary() 
  *     initializes the object
  *
  * void addWord(word)
  *     adds words to the data structure, it can be matched later
  *
  * bool search(word)
  *     returns true if there is any string in the data structure that
  *     matches word or false otherwise. word may contain dots '.' where
  *     dots can be matched with any letter.
  */
#include <string>
using namespace std;

struct Node {
    bool isWord;
    char letters[26];
};

class WordDictionary {
    
public:
    WordDictionary() {

    }

    void addWord(string word) {

    }

    bool search(string word) {
        return searchHelper(word, 0);
    }

    /*
       recursive helper function for searching for word
    */
    bool searchHelper(string word, int ndx) {

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
