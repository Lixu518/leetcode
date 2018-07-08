#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

TreeNode * helper(vector<int>&preorder, vector<int>&inorder, int lp, int rp, int li, int ri){
    if(lp > rp) return NULL;
    TreeNode *root = new TreeNode(preorder[lp]);

    for(int k = li;k <= ri;k++){
        if(preorder[lp] == inorder[k]){
            root->left = helper(preorder, inorder, lp, lp + k - li, li, k-1);
            root->right = helper(preorder, inorder, lp + k - li + 1, rp, k+1, ri);
        }
    }
    return root;
}

TreeNode* buildTree(vector<int>&preorder, vector<int>&inorder){
    if(preorder.empty() || preorder.size() == 0 || preorder.size() != inorder.size())
        return NULL;
    return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

int main(){
	vector<int>preorder = {3,9,20,15,7};
	vector<int>inorder = {9,3,15,20,7};
	TreeNode *root = buildTree(preorder, inorder);
	return 0; 
}
