#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(!root || p == root || q == root) return root;
	TreeNode *left = lowestCommonAncestor(root->left, p, q);
	if(left && left != p && left != q)return left;
	TreeNode *right = lowestCommonAncestor(root->right, p, q);
	if(right && right != p && right != q) return right;
	if(left && right) return root;
	return left ? left : right;
}
int main(){
	TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
	root->right = new TreeNode(3);
    TreeNode *res = lowestCommonAncestor(root, root->left, root->right);
    cout<<"The lowestCommonAncestor of node 2 and node 3 is node "<<(res->val)<<endl;
    return 0;
}
