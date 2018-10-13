#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){};
};

vector<int> dfs(TreeNode *root){
    if(!root) return vector<int>(2, 0);
    vector<int> left = dfs(root->left);
    vector<int> right = dfs(root->right);
    vector<int>res(2, 0);
    res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    res[1] = left[0] + right[0] + root->val;
    return res;
}
int rob(TreeNode* root) {
    vector<int> res = dfs(root);
    return max(res[0], res[1]);
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(1);
    cout<<"max rob:"<<rob(root)<<endl;
}

