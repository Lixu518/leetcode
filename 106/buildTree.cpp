#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){} 
};

TreeNode* dfs(vector<int>&inorder, vector<int>&postorder, int li, int ri, int lp, int rp){
    if(li > ri || lp > rp)return NULL;
    TreeNode* root = new TreeNode(postorder[rp]);
    for(int i = li;i <= ri;i++){
        if(inorder[i] == postorder[rp]){
            root->left = dfs(inorder, postorder, li, i - 1, lp, lp + i - li - 1);
            root->right = dfs(inorder, postorder, i + 1, ri, lp + i -li, rp - 1);
        }
    }
    return root;
}

TreeNode* buildTree(vector<int>&inorder, vector<int>&postorder){
    if(inorder.empty() || postorder.empty() || inorder.size() != postorder.size())return NULL;
    return dfs(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

int main(){
    vector<int>inorder = {9,3,15,20,7}, postorder = {9,15,7,20,3};
    TreeNode* root = buildTree(inorder, postorder);
    cout<<"OK"<<endl;
    return 0;
}
