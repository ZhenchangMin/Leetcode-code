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
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int left = 0, right = 0;
        if (!root)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;// base case: leaf node, depth is 1
        if (root->left != nullptr)
        {
            left = maxDepth(root->left);
        }
        if (root->right != nullptr)
        {
            right = maxDepth(root->right);
        }
        return max(left, right) + 1;
    }
};