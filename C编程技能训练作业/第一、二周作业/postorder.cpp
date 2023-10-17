#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
const int N = 100010;
vector<int>  nums(N);

struct TreeNode { // 定义二叉树
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructBinaryTree(vector<int>& nums, int index) { // 构建二叉树
    if (index >= nums.size() || nums[index] == 0) {
        return NULL;
    }
    TreeNode* root = new TreeNode(nums[index]);
    root->left = constructBinaryTree(nums, 2 * index);
    root->right = constructBinaryTree(nums, 2 * index + 1);
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode*> s1, s2;
    s1.push(root);
    TreeNode* node;
    
    while (!s1.empty()) {
        node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) {
            s1.push(node->left);
        }
        if (node->right) {
            s1.push(node->right);
        }
    }
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        if(!s2.empty()){
            cout <<node->val<< " ";
        }
        else{
            cout<<node->val;
        }
    }
}

int main(){
    cin>>n;
    nums[1] = 1;
    for(int i = 1; i <= n; i++){
        cin>>nums[2*i]>>nums[2*i+1];
    }
    TreeNode* root = constructBinaryTree(nums, 1);
    // for(int i = 1; i<=n; i++){
    //     cout<<nums[i]<<" ";
    // }
    //cout<<"postorderTraversal"<<endl;
    postorderTraversal(root);
    cout<<endl;
    return 0;
}