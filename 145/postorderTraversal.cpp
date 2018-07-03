#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};
vector<int> postorderTraversal(TreeNode* root){
    vector<int>res;
    stack<TreeNode*>s;
    TreeNode *p = root;
    TreeNode *flag = NULL;
    while(p || !s.empty()){
        if(p){
            s.push(p);
            p = p->left;
        }else{
            TreeNode *cur = s.top();
            if(cur->right && flag != cur->right){
                p = cur->right;
            }else{
                res.push_back(cur->val);
                flag = cur;
                s.pop();
            }
        }
    }
    return res;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int>res = postorderTraversal(root);
    for(int i = 0;i < res.size();i++)
        cout<<res[i];
    cout<<endl;
    return 0;
}
