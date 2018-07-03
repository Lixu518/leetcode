#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode *pre = NULL, *first = NULL, *second = NULL;

void inorder(TreeNode *root){
    if(!root)                                                                                                                              
        return;
    inorder(root->left);
    if(pre && pre->val >root->val){
        if(!first)
            first = pre;
        second = root;
    }
    pre = root;
    inorder(root->right);
    }   

void recoverBST(TreeNode* root){
    if(!root)
        return;
    inorder(root);
    swap(first->val, second->val);
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    recoverBST(root);
    cout<<root->val<<" "<<root->left->val<<" "<<root->left->right->val<<endl;
}
