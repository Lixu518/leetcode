#include<iostream>
#include<string>
using namespace std;
class WordDictionary {
public:
    struct TrieNode{
        TrieNode* child[26];
        bool isWord;
        TrieNode():isWord(false){
            for(auto &a:child) a = NULL;
        }
    };
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* s = root;
        for(auto &a: word){
            int i = a - 'a';
            if(!s->child[i]) s->child[i] = new TrieNode();
            s = s->child[i];
        }
        s->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(word, root, 0);
    }
    bool searchWord(string &word, TrieNode *s, int i){
        if(i == word.size()) return s->isWord;
        if(word[i] == '.'){
            for(auto &a:s->child){
                if(a && searchWord(word, a, i+1))
                    return true;
            }
            return false;
        }
        else
            return s->child[word[i] - 'a'] && searchWord(word, s->child[word[i] - 'a'], i + 1);
    }
private:
    TrieNode* root;
};

