#include<iostream>
#include<stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

int kthSmallest(TreeNode* root, int k){
    stack<TreeNode*> s;
    TreeNode* p = root;
    while(!s.empty() || p){
        while(p){
            s.push(p);
            p = p->left;
        }
        p = s.top();
        if(--k == 0)
            return p->val;
        s.pop();
        p = p->right;
    }
}

int main(){
    TreeNode *root = new TreeNode(5);
    root->right = new TreeNode(6);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    cout<<"kth smallest:"<<kthSmallest(root, 3)<<endl;
    return 0;
}
