#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

void dfs(TreeNode *node, string tmp, vector<string>& res){
    if(!node->left && !node->right) return res.push_back(tmp + to_string(node->val));
    if(node->left) dfs(node->left, tmp + to_string(node->val) + "->", res);
    if (node->right) dfs(node->right, tmp + to_string(node->val) + "->", res);
}

vector<string> binaryTreePaths(TreeNode *root){
    vector<string> res;
    if(root) dfs(root, "", res);
    return res;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    vector<string> res = binaryTreePaths(root);
    for(auto s: res)
        cout<<s<<" ";
    cout<<endl;
    return 0;
}
