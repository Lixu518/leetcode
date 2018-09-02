#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct TrieNode{
    TrieNode* child[26];
    string str;
    TrieNode():str(""){
        for(auto &a: child) a = NULL;
    }
};

struct Trie{
    TrieNode* root;
    Trie():root(new TrieNode()){}
    void insert(string s){
        TrieNode* p = root;
        for(auto &a:s){
            int i = a - 'a';
            if(!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->str = s;
    }
};

void search(vector<vector<char> > &board, TrieNode* p, int i, int j,
        vector<vector<bool> > &visited, vector<string> &res){
    if(!p->str.empty()){
        res.push_back(p->str);
        p->str.clear();
    }
    int d[4][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
    visited[i][j] = true;
    for(auto &a:d){
        int row = a[0] + i, col = a[1] + j;
        if(row >= 0 && row < board.size() && col >= 0 && col < board[0].size()
                && !visited[row][col] && p->child[board[row][col] - 'a'])
            search(board, p->child[board[row][col] - 'a'], row, col, visited,
                    res);
    }
    visited[i][j] = false;
}

vector<string> wordSearch(vector<vector<char> > &board, vector<string> &words){
    vector<string> res;
    if(board.empty() || board[0].empty() || words.empty()) return res;
    vector<vector<bool> >visited(board.size(), vector<bool>(board[0].size(),
                false));
    Trie T;
    for(auto &a: words) T.insert(a);
    for(int i = 0;i < board.size();i++){
        for(int j = 0;j < board[0].size();j++){
            if(T.root->child[board[i][j] - 'a']){
                search(board, T.root->child[board[i][j] - 'a'], i, j, visited,
                        res);
            }
        }
    }
    return res;
}

int main(void){
    vector<vector<char> >board = {{'o','a','a','n'},
                                {'e','t','a','e'},
                                {'i','h','k','r'},
                                {'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> res = wordSearch(board, words);
    for(auto str:res)
        cout<<str<<" ";
    cout<<endl;
    return 0;
}

