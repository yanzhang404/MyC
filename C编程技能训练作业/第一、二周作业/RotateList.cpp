#include <iostream>
using namespace std;

struct ListNode{ //定义链表节点
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* createList(int arr[], int n){     // 创建链表
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
 
void printList(ListNode* head){   //打印链表

    ListNode* current = head;
    while( current != NULL){
        cout<<current->val<<" ";
        current = current->next;
    }
    cout<<endl;
}

void rotate(int arr[], int l, int r){
    int temp;
    while(l < r){
        temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}
int main(){
    int n, k; //
    cin>>n>>k;
    int arr[n];
    for(int i =0; i<n;i++){
        cin>>arr[i];
    }
    if(k > n)   k = k % n;
    rotate(arr,0,n-k-1);
    rotate(arr,n-k,n-1);
    rotate(arr,0,n-1);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //ListNode* p = createList(arr,n);
    //printList(p);
    return 0;
}