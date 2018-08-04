#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

void dfs(TreeNode* root, vector<int>& temp, vector<vector<int>>& res, int sum){
    if(!root) return;
    temp.push_back(root->val);
    if(sum == root->val && !root->left && !root->right)
        res.push_back(temp);
    dfs(root->left, temp, res, sum - root->val);
    dfs(root->right, temp, res, sum - root->val);
    temp.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum){
    vector<int>temp;
    vector<vector<int>> res;
    dfs(root, temp, res, sum);
    return res;
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    vector<vector<int>> res = pathSum(root, 22);
    for(auto row : res){
        for(auto num : row)
            cout<<num;
        cout<<endl;
    }
    return 0;
}
