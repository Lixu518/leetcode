#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

int helper(TreeNode* node, int& res){
    if(!node)return 0;
    int left = max(helper(node->left, res), 0);
    int right = max(helper(node->right, res), 0);
    res = max(res, left + right + node->val);
    return max(left, right) + node->val;
}

int maxPathSum(TreeNode* root){
    int res = INT_MIN;
    helper(root, res);
    return res;
}

int main(){
    TreeNode *root = new TreeNode(-10);
    root->right = new TreeNode(20);
    root->left = new TreeNode(9);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int res = maxPathSum(root);
    cout<<res<<endl;
    return 0;
}
