#include<iostream>
#include<string>
using namespace std;

class TrieNode{
    public:
        TrieNode *child[26];
        bool isWord;
        TrieNode():isWord(false){
            for(auto &a:child)
                a = NULL;
        }
};

class Trie{
    private:
        TrieNode* root;

    public:
        Trie(){
            root = new TrieNode();
        }

        void insert(string word){
            TrieNode* s = root;
            for(auto &a: word){
                int i = a - 'a';
                if(!s->child[i]) s->child[i] = new TrieNode();
                s = s->child[i];
            }
            s->isWord = true;
        }

        bool search(string word){
            TrieNode* s = root;
            for(auto &a: word){
                int i = a - 'a';
                if(!s->child[i]) return false;
                s = s->child[i];
            }
            return s->isWord;
        }

        bool startsWith(string prefix){
            TrieNode* s = root;
            for(auto &a:prefix){
                int i = a - 'a';
                if(!s->child[i]) return false;
                s = s->child[i];
            }
            return true;
        }
};

int main(){
    Trie trie = new Trie();
    trie.insert("apple");
    trie.search("apple");   
    trie.search("app");     
    trie.startsWith("app"); 
    trie.insert("app");
    trie.search("app");     
}

