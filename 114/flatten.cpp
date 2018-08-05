#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

void flatten(TreeNode* root){
    TreeNode* cur = root;
    while(cur){
        if(cur->left){
            TreeNode* p = cur->left;
            while(p->right) p = p->right;
            p->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    flatten(root);
    while(root){
        cout<<root->val;
        root = root->right;
    }
    return 0;
}
