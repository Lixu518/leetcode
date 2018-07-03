#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

vector<int> preorderTraversal(TreeNode *root){
    vector<int>res;
    stack<TreeNode*>s;
    TreeNode *p = root;
    while(!s.empty() || p){
        if(p){
            s.push(p);
            res.push_back(p->val);
            p = p->left;
        }else{
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
    return res;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int>res = preorderTraversal(root);
    for(int i = 0;i < res.size();i++){
        cout<<res[i];
    }
    cout<<endl;
    return 0;
}
