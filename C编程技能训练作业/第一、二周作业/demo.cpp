#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildBinaryTree(vector<vector<int> >& nums) {
    if (nums.empty()) {
        return NULL;
    }
    
    int n = nums.size();
    vector<TreeNode*> nodes(n + 1);  // 用于存储每个节点的指针
    
    // 创建每个节点
    for (int i = 1; i <= n; i++) {
        nodes[i] = new TreeNode(nums[i - 1][2]);
    }
    
    // 建立节点之间的连接关系
    for (int i = 1; i <= n; i++) {
        int leftIndex = nums[i - 1][0];
        int rightIndex = nums[i - 1][1];
        
        if (leftIndex != 0) {
            nodes[i]->left = nodes[leftIndex];
        }
        if (rightIndex != 0) {
            nodes[i]->right = nodes[rightIndex];
        }
    }
    
    return nodes[1];  // 返回根节点的指针
}
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}
int main() {
    int n;
    cin >> n;
    
    vector<vector<int> > nums(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
    }
    
    TreeNode* root = buildBinaryTree(nums);
    
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}