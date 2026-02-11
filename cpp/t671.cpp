/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <climits>
class Solution
{
public:
    void dfs(TreeNode *node, int smallest, long &ans)
    {
        if (!node)
            return;
        if (node->val > smallest && node->val < ans)
            ans = node->val;
        dfs(node->left, smallest, ans);
        dfs(node->right, smallest, ans);
    }

    int findSecondMinimumValue(TreeNode *root)
    {
        if (!root)
            return -1;
        long ans = LONG_MAX;
        dfs(root, root->val, ans);
        return ans == LONG_MAX ? -1 : ans;
    }
};
