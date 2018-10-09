#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode *s, *even=head->next, *odd = head,*p;
    s = even;
    p = odd;
    while(even && even->next){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = s;
    return p;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    ListNode* res = oddEvenList(head);
    cout<<"res: "<<res->val<<"\nres->next: "<<res->next->val<<endl;
    cout<<"res->next->next: "<<res->next->next->val<<endl;
    return 0;
}
