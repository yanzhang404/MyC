#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
struct TreeNode
{ // 定义二叉树
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (!preorder.size())
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[0]);
    stack<TreeNode *> stk;
    stk.push(root);
    int inorderIndex = 0;
    for (int i = 1; i < preorder.size(); ++i)
    {
        int preorderVal = preorder[i];
        TreeNode *node = stk.top();
        if (node->val != inorder[inorderIndex])
        {
            node->left = new TreeNode(preorderVal);
            stk.push(node->left);
        }
        else
        {
            while (!stk.empty() && stk.top()->val == inorder[inorderIndex])
            {
                node = stk.top();
                stk.pop();
                ++inorderIndex;
            }
            node->right = new TreeNode(preorderVal);
            stk.push(node->right);
        }
    }
    return root;
}

void PostOrder(TreeNode* root){
    if(root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->val<<" ";
}

int main()
{
    cin >> n;
    vector<int> pre(n);
    vector<int> post(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    TreeNode* root = buildTree(pre, post);
    PostOrder(root);
    cout<<endl;
    return 0;
}
