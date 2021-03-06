#include<iostream>
using namespace std;
struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x):val(x), left(NULL), right(NULL), next(NULL){}
};

void connect(TreeLinkNode *root){
    if(!root) return;
    TreeLinkNode *start = root, *cur = NULL;
    while(start->left){
        cur = start;
        while(cur){
            cur->left->next = cur->right;
            if(cur->next)cur->right->next = cur->next->left;
            cur = cur->next;
        }
        start = start->left;
    }
}


