#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int n;
const int N = 100010;
int maxSum = INT_MIN;

struct TreeNode
{ // 定义二叉树
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildBinaryTree(vector<vector<int> > &nums)
{
    if (nums.empty())
    {
        return NULL;
    }

    int n = nums.size();
    vector<TreeNode *> nodes(n + 1); // 用于存储每个节点的指针

    // 创建每个节点
    for (int i = 1; i <= n; i++)
    {
        nodes[i] = new TreeNode(nums[i - 1][2]);
    }

    // 建立节点之间的连接关系
    for (int i = 1; i <= n; i++)
    {
        int leftIndex = nums[i - 1][0];
        int rightIndex = nums[i - 1][1];

        if (leftIndex != 0)
        {
            nodes[i]->left = nodes[leftIndex];
        }
        if (rightIndex != 0)
        {
            nodes[i]->right = nodes[rightIndex];
        }
    }

    return nodes[1]; // 返回根节点的指针
}

int maxGain(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    // 递归计算左右子节点的最大贡献值
    // 只有在最大贡献值大于 0 时，才会选取对应子节点
    int leftGain = max(maxGain(node->left), 0);
    int rightGain = max(maxGain(node->right), 0);

    // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
    int priceNewpath = node->val + leftGain + rightGain;

    // 更新答案
    maxSum = max(maxSum, priceNewpath);

    // 返回节点的最大贡献值
    return node->val + max(leftGain, rightGain);
}

int maxPathSum(TreeNode *root)
{
    maxGain(root);
    return maxSum;
}

int main()
{
    cin >> n;
    vector<vector<int> > nums(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
    }

    TreeNode *root = buildBinaryTree(nums);
    int res = maxPathSum(root);
    cout<<res<<endl;
    return 0;
}