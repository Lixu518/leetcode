#include<iostream>
#include<cmath>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};
int countNodes(TreeNode *root){
    int lh = 0, rh = 0;
    TreeNode *pleft = root, *pright = root;
    while(pleft){
        lh++;
        pleft = pleft->left;
    }
    while(pright){
        rh++;
        pright = pright->right;
    }
    if(lh == rh) return pow(2, lh) - 1;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    cout<<"Node num:"<<countNodes(root)<<endl;
    return 0;
}

