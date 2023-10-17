#include <iostream>
using namespace std;

struct ListNode{ //定义链表节点
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};


ListNode* Reverse(ListNode* head, int l, int r){
    if(head == NULL || l>=r){
        return head;
    }

    ListNode* p = new ListNode(0); //头节点
    p->next = head;
    ListNode* prev = p; //prev指向要反转的起始节点的前一个节点
    for(int i = 1; i < l; i++){
        prev = prev->next;
    }
    ListNode* current = prev->next; //current  指向当前节点
    ListNode* next = NULL;      //next 指向下一个节点

    for(int i = l; i<r; i++){
        next = current->next;
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    return p->next;

}


ListNode* createList(int arr[], int n){
    if (n == 0)
    {
        return NULL;
        /* code */
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for( int i = 1; i< n; i++){
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head){
    ListNode* current = head;
    while( current != NULL){
        cout<<current->val<<" ";
        current = current->next;
    }
    cout<<endl;
}

int main(){
    int n,l,r;
    cin>>n>>l>>r;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    ListNode* head = createList(arr,n);
    head = Reverse(head,l,r);
    printList(head);
    return 0;
}