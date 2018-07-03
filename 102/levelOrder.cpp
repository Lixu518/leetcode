#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
}; 

    vector<vector<int>> res;

void dfs(TreeNode *root, int height){
    if(!root)   return;
    if(res.size() <= height){
        res.push_back(vector<int>());
    }
    res[height].push_back(root->val);
    dfs(root->left, height+1);
    dfs(root->right, height+1);
}

vector<vector<int>> levelOrder(TreeNode *root){
    if(!root) return res;
    dfs(root, 0);
    return res;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<vector<int>> res = levelOrder(root);
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
