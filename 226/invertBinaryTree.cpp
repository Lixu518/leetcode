#include<iostream>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode* invertTree(TreeNode *root){
    if(!root) return root;
    TreeNode *tmp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp);
    return root;
}

TreeNode* invertBinaryTree(TreeNode* root){
    if(!root)return root;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return root;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    TreeNode *root1 = invertTree(root);
    TreeNode *root2 = invertBinaryTree(root);
    cout<<"Two way have the same answer:"<<(root1->left == root2->left)<<endl;
    return 0;
}

