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
    int minDepth(TreeNode *root)
    {
        int left = INT_MAX, right = INT_MAX;
        if (!root)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1; // base case: leaf node, depth is 1
        if (root->left != nullptr)
        {
            left = minDepth(root->left);
        }
        if (root->right != nullptr)
        {
            right = minDepth(root->right);
        }
        return min(left, right) + 1;
    }
};