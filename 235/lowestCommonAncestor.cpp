#include<iostream>
#include<cmath>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return NULL;
    else if(root->val > max(p->val, q->val)){
        return lowestCommonAncestor(root->left, p, q);
    }else if (root->val < min(p->val, q->val)){
        return lowestCommonAncestor(root->right, p, q);
    } else{
        return root;
    }
}

int main(){
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    TreeNode *res = NULL;
    res = lowestCommonAncestor(root, root->left->left, root->right->left);
    cout<<"The lowestCommonAncestor of node0 and node7 is node: "<<(res->val)<<endl;
    return 0;
}
