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
    vector<int> leafArray(TreeNode *root) // dfs to get leaf sequence
    {
        vector<int> ans;
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(root->val);
        }
        vector<int> temp;
        if (root->left != nullptr)
        {
            temp = leafArray(root->left);
            for (int i = 0; i < temp.size(); i++)
                ans.push_back(temp[i]);
        }
        if (root->right != nullptr)
        {
            temp = leafArray(root->right);
            for (int i = 0; i < temp.size(); i++)
                ans.push_back(temp[i]);
        }
        return ans;
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        return leafArray(root1) == leafArray(root2);
    }
};