#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

vector<TreeNode*> genTree(int left, int right){
    vector<TreeNode*>res;
    if(left > right) res.push_back(NULL);
    for(int i = left;i <= right;i++){
        vector<TreeNode*>leftList = genTree(left,i-1);
        vector<TreeNode*>rightList = genTree(i+1, right);
        for(auto left:leftList)
            for(auto right:rightList){
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                res.push_back(root);
            }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    if(n == 0)  return vector<TreeNode*>();
    else return genTree(1, n);
}

int main(){
    
}

