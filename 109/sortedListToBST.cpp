#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL){}
};

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

TreeNode* build(ListNode* start, ListNode* end){
    if(start == end) return NULL;
    ListNode* fast = start, *slow = start;
    while(fast != end && fast->next != end){
        fast = fast->next->next;
        slow = slow->next;
    }
    TreeNode *node = new TreeNode(slow->val);
    node->left = build(start, slow);
    node->right = build(slow->next, end);
    return node;
}

TreeNode* sortedListToBST(ListNode* head){
    return build(head, NULL);
}

int main(){
    ListNode* head = new ListNode(-10);
    vector<int>nums = {-10, -3, 0, 5,9};
    ListNode * prehead = head;
    for(int i = 1;i < nums.size();i++){
        head = new ListNode(nums[i]);
        head = head->next;
    }
    TreeNode *root = sortedListToBST(prehead);
    cout<<root->val<<" "<<endl;
    return 0;
}
