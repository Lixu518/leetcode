#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

int dfs(TreeNode* root, int sum){
    if(!root)return 0;
    sum = sum*10 + root->val;
    if(!root->left && !root->right) return sum;
    return dfs(root->left, sum) + dfs(root->right, sum);
}

int sumNumbers(TreeNode *root){
    return dfs(root, 0);
}

int main(){
    TreeNode*root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout<<"sum numbers:"<<sumNumbers(root)<<endl;
    return 0;
}
