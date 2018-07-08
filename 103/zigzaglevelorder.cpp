#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL),right(NULL){}
};

vector<vector<int>> zigzaglevelorder(TreeNode* root){
    vector<vector<int>>res;
    if(!root) return res;
    queue<TreeNode*>q;
    q.push(root);
    bool l2r = true;
    while(!q.empty()){
        int n = q.size();
        vector<int>tmp(n);
        for(int i = 0;i < n;i++){
            TreeNode *node = q.front();
            q.pop();
            int index = l2r ? i :(n - 1 -i);
            tmp[index] = node->val;
            if(node->left) q.push(node->left);

            if(node->right) q.push(node->right);
        }
        l2r = !l2r;
        res.push_back(tmp);
    }
    return res;
}

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>>res = zigzaglevelorder(root);
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++)
            cout<<res[i][j];
        cout<<endl;
    }
    return 0;
}
