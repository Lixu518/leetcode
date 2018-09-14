#include<iostream>
#include<sstream>
#include<string>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Codec{
    public:
        string serialize(TreeNode *root){
            ostringstream out;
            serialize(root, out);
            return out.str();
        }
        TreeNode* deserialize(string data){
        istringstream in(data);
        return deserialize(in);
        }
    private:
        void serialize(TreeNode* root, ostringstream &out){
            if(root){
                out<<root->val<<' ';
                serialize(root->left, out);
                serialize(root->right, out);
            }
            else{
                out<<"# ";
            }
        }

        TreeNode* deserialize(istringstream &in){
            string val;
            in >> val;
            if(val == "#")return nullptr;
            TreeNode* root = new TreeNode(stoi(val));
            root->left = deserialize(in);
            root->right = deserialize(in);
            return root;
        }
};

int main(){
    Codec cc;
    TreeNode *root= new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    string se = cc.serialize(root);
    cout<<"serialize:"<<se<<endl;
    TreeNode *node = cc.deserialize(se);
    cout<<"root node of deserialize:"<<node->val<<endl;
    return 0;
}
